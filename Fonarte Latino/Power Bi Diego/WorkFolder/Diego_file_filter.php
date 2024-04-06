<?php

/*
	Filtración de archivos para remover texto no deseado y limpiar las tablas del mes correspondiente.
	Al final se correo un archivo .bat para terminar de actualizar las tablas en la base de datos.
	
	Andrés P. - 28 de Agosto de 2018
*/

// Set folder path
define("FOLDER_PATH", ".\REPORTES_FONARTE");

// Set default year and month with negative sign
$col_year  = "-" . date("Y");
$col_month = "-" . date("n");

// Check if there are zip files and extract them
$dir = new DirectoryIterator(FOLDER_PATH);
foreach ($dir as $fileinfo) if (!$fileinfo->isDot()) if($fileinfo->getExtension() == 'zip') extractZipFile($fileinfo->getPathname(), FOLDER_PATH);

// Check if there are any folders
$dir = new DirectoryIterator(FOLDER_PATH);
foreach ($dir as $fileinfo) {
	if (!$fileinfo->isDot()) {
		if($fileinfo->getType() == 'dir'){
			if(strpos($fileinfo->getFilename(), 'apple') !== false) {
				$apple_dir = new DirectoryIterator($fileinfo->getPathname());
				foreach ($apple_dir as $apple_fileinfo) if (!$apple_fileinfo->isDot()) copy($apple_fileinfo->getPathname(), (FOLDER_PATH . "\\" . $apple_fileinfo->getFilename()));
				if(strlen($fileinfo->getPathname()) < 5) printf("ALERT: problem deleting folder [%s] because it looks too short and could be a wrong path.\n", $fileinfo->getPathname());
				else delete_directory($fileinfo->getPathname());
			}
			else {
				if(strlen($fileinfo->getPathname()) < 5) printf("ALERT: problem deleting folder [%s] because it looks too short and could be a wrong path.\n", $fileinfo->getPathname());
				else delete_directory($fileinfo->getPathname());
			}
		}
	}
}

// Get real month and year from orchard original file
$dir = new DirectoryIterator(FOLDER_PATH);
foreach ($dir as $fileinfo) {
	if (!$fileinfo->isDot()) {
		if(strpos($fileinfo->getFilename(), 'fullreport_fonarte') !== false && $fileinfo->getExtension() == 'xls') {
			$fp = fopen($fileinfo->getPathname(), 'r'); // Open xls
			$line = fgets($fp); // Skip headers
			$line = fgets($fp); // Get first data row
			$line = mb_convert_encoding($line, 'UTF-8', 'UCS-2'); // Convert to UTF8
			$line = str_replace('"','',$line); // Remove ["]
			$data = str_getcsv(utf8_decode($line), "\t"); // Get columns separated by a tab
			$col_year  = strstr($data[0], "M", true); // year
			$col_month = substr(strstr($data[0], "M"), 1); // month
			fclose($fp); // Close files
		}			
	}
}

// Loop through files 
$dir = new DirectoryIterator(FOLDER_PATH);
foreach ($dir as $fileinfo) {
	if (!$fileinfo->isDot()) {
		///// APPLE MUSIC
		/*if((strpos($fileinfo->getFilename(), '_ZZ') !== false) && (strpos($fileinfo->getFilename(), 'S1_') !== false)) {
			printf("Getting [Apple Music] ready...");
			// Set new and old file paths
			$old_file = $fileinfo->getPathname();
			$new_file = strstr($fileinfo->getPathname(), ".txt", true) . "-clean.txt";
			// Check if file already exists
			if(file_exists($new_file)) {
				printf(" file already exists.\n");
				continue;
			}
			// Initialize file looping variables
			$lines = file($old_file, FILE_IGNORE_NEW_LINES); // Read file into array
			$new_content = '';
			// Loop through each row and column
			foreach($lines as $index => $row){
				if($index == 0 || $index == 1 || $index == 2 || $index == 3) continue;
				if(strpos($row, "Row Count\t") !== false) break;
				$new_content .= $row . "\t" . $col_year . "\t" . $col_month . "\n";
			}
			file_put_contents($new_file, rtrim($new_content)); // save new clean file
			unlink($old_file); // Delete old file
			printf(" done.\n");
		}
		///// ITUNES
		elseif(strpos($fileinfo->getFilename(), '_ZZ') !== false) {
			printf("Getting [Itunes] ready...");
			// Set new and old file paths
			$old_file = $fileinfo->getPathname();
			$new_file = strstr($fileinfo->getPathname(), ".txt", true) . "-clean.txt";
			// Check if file already exists
			if(file_exists($new_file)) {
				printf(" file already exists.\n");
				continue;
			}
			// Initialize file looping variables
			$lines = file($old_file, FILE_IGNORE_NEW_LINES); // Read file into array
			$new_content = '';
			// Loop through each row and column
			foreach($lines as $index => $row){
				if($index == 0) continue;
				if(strpos($row, "Total_Rows\t") !== false) break;
				$new_content .= $row . "\t" . $col_year . "\t" . $col_month . "\n";
			}
			file_put_contents($new_file, rtrim($new_content)); // save new clean file
			unlink($old_file); // Delete old file
			printf(" done.\n");
		}
		///// ORCHARD
		elseif(strpos($fileinfo->getFilename(), 'fullreport_fonarte') !== false && $fileinfo->getExtension() == 'xls') {
			printf("Getting [Orchard] ready...");
			// Set new and old file paths
			$old_file = $fileinfo->getPathname();
			$new_file = strstr($fileinfo->getPathname(), ".xls", true) . "-clean.txt";
			// Check if file already exists
			if(file_exists($new_file)) {
				printf(" file already exists.\n");
				continue;
			}
			// Initialize file looping variables
			$fp = fopen($old_file, 'r'); // Open xls
			$line = fgets($fp); // Skip first row (headers)
			$new_content = '';
			// Loop through rows
			while (!feof($fp)){
				$line = fgets($fp); // Get row
				$data = str_getcsv($line, "\t"); // Get columns separated by a tab
				$temp_arr = array();
				// Loop through columns and filter data
				foreach($data as $index => $row) {
					$str = mb_convert_encoding($row, 'UTF-8', 'UCS-2'); // Convert to UTF8
					$str = str_replace('"','',$str); // Remove ["] 
					$temp_arr[] = utf8_decode($str); // Save into temp array
				}
				if(sizeof($temp_arr) > 2){
					$temp_arr[] = $col_year; // Add year
					$temp_arr[] = $col_month; // Add month
					// Append new row to final string
					$new_content .= implode("\t",$temp_arr) . "\n";
				}
			}
			// Write the new content into the txt file
			$new_content = utf8_encode($new_content);
			file_put_contents($new_file, $new_content);
			fclose($fp); // Close files
			unlink($old_file); // Delete old file
			printf(" done.\n");
		}
		///// EXCHANGE RATE
		else*/if(strpos($fileinfo->getFilename(), 'financial_') !== false && $fileinfo->getExtension() == 'csv') {
			printf("Getting [Exchange Rate] ready...");
			// Set new and old file paths
			$old_file = $fileinfo->getPathname();
			$new_file = strstr($fileinfo->getPathname(), ".csv", true) . "-clean.txt";
			// Check if file already exists
			if(file_exists($new_file)) {
				printf(" file already exists.\n");
				continue;
			}
			// Initialize file looping variables
			$lines = file($old_file, FILE_IGNORE_NEW_LINES); // Read file into array
			$new_content = '';
			$temp_arr = array();
			// Loop through each row and column
			foreach($lines as $index => $row){
				if($index == 0 || $index == 1 || $index == 2) continue;
				$str = str_replace('"','',$row); // Remove ["]
				$temp_arr = explode(',',$str);
				if($temp_arr[0] == '') break;
				array_pop($temp_arr);
				$temp_arr[] = $col_year;
				$temp_arr[] = $col_month;
				$new_content .= implode("\t",$temp_arr) . "\n";
			}
			file_put_contents($new_file, rtrim($new_content)); // save new clean file
			unlink($old_file); // Delete old file
			printf(" done.\n");
		}
		
	}
}

// Function to extract zip files
function extractZipFile($file, $path) {
	$zip = new ZipArchive;
	$res = $zip->open($file);
	if ($res === TRUE) {
		$zip->extractTo($path);
		$zip->close();
		unlink($file); // Delete the zip file
		printf("ZIP file [%s] extracted.\n", $file);
	} 
	else {
		printf("ERROR: ZIP file [%s] could not be extracted.\n", $fileinfo->getFilename());
		exit();
	}
}

// Function that deals with directories recursively and deletes full directory
function delete_directory($dirname) {
	if (is_dir($dirname)) $dir_handle = opendir($dirname);
	if (!$dir_handle) return false;
	while($file = readdir($dir_handle)) {
		if ($file != "." && $file != "..") {
			if (!is_dir($dirname."/".$file)) unlink($dirname."/".$file);
			else delete_directory($dirname.'/'.$file);
		}
	}
	closedir($dir_handle);
	rmdir($dirname);
	return true;
}
