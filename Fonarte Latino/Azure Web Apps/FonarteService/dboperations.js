var config = require('./dbconfig');
const sql = require('mssql');
const mysql = require('mysql');

async function addArtista(artistas){
    try{
        let pool = await sql.connect(config);
        let insertArtist = await pool.request()
        .input('sello_id', sql.Int, NULL)
        .input('nombre', sql.NVarChar, artistas.nombre)
        .execute('Insertartista');
        return insertArtist.recordsets;
    }
    catch (error){
        console.log(error);
    }
}

async function artistas(){
    /*try{
        let pool = await sql.connect(config);
        let products = await pool.request().query("SELECT * FROM `artista`") 
        return products.recordsets;
    }
    catch(error){
        console.log(error);
    }*/
    try{
        mysql.createPool()        
    }
    catch(error){

    }
}

module.exports ={
    addArtista : addArtista,
    artistas : artistas
}