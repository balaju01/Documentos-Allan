const mysql = require('mysql');

const {promisify} = require('util');

const database = require('./dbconfig');

const pool = mysql.createPool(database.configMysql);

pool.getConnection((err,connection) => {
    if (err) {
        if (err.code === 'PROTOCOL_CONNECTION_LOST') {
            console.error('La coneccion a la base de datos se a cerrado');
        }
        if (err.code === 'ER_CON_COUNT_ERROR') {
            console.error('Hay demaciadas conexiones a la base de datos');
        }
        if (err.code === 'ECONNREFUSED') {
            console.error('Coneccion rechasada');
        }
    }

    else if(connection) connection.release();
    console.log('DB conectado');
    return;
});

pool.query = promisify(pool.query);

module.exports = pool;