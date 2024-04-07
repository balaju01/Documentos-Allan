//Rutas de conexion DB para Desarrollo
const config = {
    user: 'root',
    password: '',
    server: 'http://localhost/phpmyadmin/db_structure.php',
    database: "resumen_regalias",
    'requestTimeout': 480000,
    options: {
        'enableArithAbort': true,
        'idleTimeoutMillis': 480000
    }
};

const configMysql = {
    host : 'localhost',
    user: 'root',
    password: '',
    database: "resumen_regalias"
};

//Rutas de conexio DB para Produccion
/*const config = {
    user: 'root',
    password: '',
    server: 'http://localhost/phpmyadmin/db_structure.php',
    database: "resumen_regalias",
    'requestTimeout': 480000,
    options: {
        'enableArithAbort': true,
        'idleTimeoutMillis': 480000
    }
};

const configMysql = {
    host : 'localhost',
    user: 'root',
    password: '',
    database: "resumen_regalias"
};*/

module.exports = {
    config : config,
    configMysql : configMysql

};