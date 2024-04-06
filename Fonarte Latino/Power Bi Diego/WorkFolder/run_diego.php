<?php

// Set timer
$time_start = microtime(true); 

// Set timezone 
date_default_timezone_set("America/Mexico_City");

// Set log folde path
define("LOG_PATH", 'C:/xampp/htdocs/WorkFolder/log');
define("FOLDER_PATH", 'C:/Users/DELL/Documents/REPORTES_FONARTE');
define("BAT_FILE", 'C:/Users/DELL/Documents/loadfiles.bat');

// Display user output
printf("Running [Diego DB data update] program, please wait... ");

// Exit if no files found within folder path
if (dir_is_empty(FOLDER_PATH)) exit;

// Check if log file exists
if (!is_dir( LOG_PATH )) mkdir( LOG_PATH , 0777, true); // create log file

// Create log file name
$log_file_name = date("Y_m_d_His");

// Set output string
$output_str = "";

// Run main script
$output_str .= shell_exec('C:/xampp/php/php.exe -f C:/xampp/htdocs/WorkFolder/Diego_file_filter.php');

// Run bat file
$output_str .= shell_exec('cmd /C ' . BAT_FILE . ' 2>&1');
 
// Stop timer
$time_end = microtime(true);

//dividing with 60 will give the execution time in minutes otherwise seconds
$output_str .= 'Total execution time: ' . round(($time_end - $time_start)/60,2) . " min\n";

// Save log string only if there was an execution
file_put_contents(LOG_PATH . '/' . $log_file_name . '.txt', $output_str);

// Display user output
printf("done\n");

// Function to check if folder path has any files within it
function dir_is_empty($dir) {
	$handle = opendir($dir);
	while (false !== ($entry = readdir($handle))) {
		if ($entry != "." && $entry != "..") {
			return FALSE;
		}
	}
	return TRUE;
}