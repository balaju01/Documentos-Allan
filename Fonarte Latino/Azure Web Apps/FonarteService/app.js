const dboperations = require('./dboperations');
var DB = require('./dboperations');
var Objet = require('./Objets');
var conection = require('./links');
var remplaced = require('replaceall');

var express = require('express');
const jwt = require("jsonwebtoken");
var axios = require('axios');
var bodyParser = require('body-parser');
var cors = require('cors');
var app = express();
var router = express.Router();
const pool = require('./dbconexionmysql');
const { request } = require('https');
const { response } = require('express');
const crypto = require('bcryptjs');

app.use(bodyParser.urlencoded({extended:true}));
app.use(bodyParser.json());
app.use(cors());
app.use('/api',router);
 
router.use((request,response,next)=>{
    console.log('middleware');
    next(); 
});

router.route('/').get(async (request,response)=>{
    console.log("linea 30");
    console.log(conection.api_Master);
    response.json({
        mensaje: "Nodejs y JWT"
    });
});

router.route('/login').post(async (request,response)=>{
    console.log(request.body);
    //let q = 'SELECT * FROM `sello` WHERE `usr`= BINARY \''+request.body.usr+'\' and `psw` = BINARY \''+request.body.psw+'\'';
    let q = 'SELECT * FROM `sello` WHERE `usr`= BINARY \''+request.body.usr+'\'';

    var result = await pool.query(q);
    console.log(result);
    if(result.length == 0) {
        console.log("No existe el usuario");
        response.status(400).json("Usuario no encontrado");
    }else {
        //console.log(await crypto.compare(result[0].psw,request.body.psw));
        if (result[0].psw !== request.body.psw) {
            response.status(403).json("Error de pasword");
            console.log("no es el pasword");
        }else {
            jwt.sign({id: result[0].id}, 'secretkey', {expiresIn:86400}, (err,token)=>{
                response.status(200).json({
                    token: token,
                    usuario : result[0]
                })
            });
        }
    }
});

router.route('/prueba').post(verifyToken,(request,response)=>{
    console.log("seguimos")
    response.status(200).json("fin prueba")
});

async function verifyToken(req, res , next){
    const bearerHeader = req.headers['authorization'];
    console.log("a ver espero si verifique")
    if(typeof bearerHeader !== 'undefined'){
        const bearerToken = bearerHeader.split(" ")[1];
        req.token = bearerToken;
        try {
            var tval = jwt.verify(req.token,'secretkey');
            let q = 'SELECT `id`,`nombre`,`rol`,`usr` FROM `sello` WHERE `id`='+tval.id;
            var result = await pool.query(q);
            //console.log(result);
            console.log(result[0]);
            if (result[0] == undefined){
                res.status(404).json("No hay usuario");
            }else {
                console.log(tval);
                next();
            }
        } catch (error) {
            res.status(401).json("No autorizado");
        }  
    }else{
        res.status(403).json("No hay token");
    }
}

router.route('/artists/inicial').get(async (request,response)=>{
    let respuesta;
    await axios({
        method: 'GET',
        url: conection.api_Master+'/artistas'
    }).then(res=>{
        respuesta = res.data;    
    }).catch(err => console.log(err))
    let q = 'INSERT INTO `artista`(`nombre`) VALUES ';
    console.log(respuesta)
    let c = 0;
    respuesta.forEach(element => {
        c = c + 1;
        q = q + '(\''
        //console.log(element);
        let e = remplaced.replaceall('\'', '\\\'',element.ARTIST);
        if (c < respuesta.length) {
            q = q + e + '\'),';
        } else {
            q = q + e + '\')';
        }
    });
    console.log(q);
    //console.log(c);
    var result = await pool.query(q);
    response.status(201).json(result);
})

router.route('/artists/actualizar').get(async (request,response)=>{
    let respuesta;
    await axios({
        method: 'GET',
        url: conection.api_Master+'/artistas'
    }).then(res=>{
        respuesta = res.data;    
    }).catch(err => console.log(err))
    //console.log(respuesta.length);
    console.log(respuesta);
    let a = 'SELECT * FROM `artista`'
    var result = await pool.query(a);
    console.log(result);
    console.log(respuesta.length);
    console.log(result.length);
    let aux = [];
    if (respuesta.length>result.length) {
        
        result.forEach(el =>{
            aux.push(el.nombre);
        });
        console.log(aux[0]);
        let c = 0;
        let q = 'INSERT INTO `artista`(`nombre`) VALUES ';
        console.log(aux.indexOf('CRISTIAN CASTRO & CARLOS MACÍAS'));
        console.log(aux.indexOf('SONALLI'));
        q = q + '(\'';
        let ins = '';
        respuesta.forEach(ele => {
            
            
            //aux.push(ele.ARTIST);
            let i = aux.indexOf(ele.ARTIST);
            //console.log(i);
            if (i == -1) {
                c = c + 1;
                console.log(ele.ARTIST);
                
                let e = remplaced.replaceall('\'', '\\\'',ele.ARTIST);
                if (c < (respuesta.length-result.length)) {
                    ins = ins + ele.ARTIST + ' , ';
                    q = q + e + '\'),(\'';
                } else {
                    ins = ins + ele.ARTIST;
                    q = q + e + '\')';
                }
            }

        });
        console.log(q);
        //var res = await pool.query(q);
        response.status(201).json(ins);
    }else if (respuesta.length<result.length) {
        
        respuesta.forEach(el =>{
            aux.push(el.ARTIST);
        });
        
        
        let c = 0;
        let q = 'DELETE FROM `artista` WHERE `nombre` = ';
        console.log(aux.indexOf('CRISTIAN CASTRO & CARLOS MACÍAS'));
        console.log(aux.indexOf('SONALLI'));
        q = q + '\'';
        let ins = '';
        result.forEach(ele => {
            
            
            //aux.push(ele.ARTIST);
            let i = aux.indexOf(ele.nombre);
            //console.log(i);
            if (i == -1) {
                c = c + 1;
                console.log(ele.nombre);
                
                let e = remplaced.replaceall('\'', '\\\'',ele.nombre);
                if (c <= (respuesta.length-result.length)) {
                    ins = ins + ele.nombre + ' , ';
                    q = q + e + '\' or `nombre` = \'';
                } else {
                    ins = ins + ele.nombre;
                    q = q + e + '\'';
                }
            }

        });
        console.log(q);
        //var res = await pool.query(q);
        
        response.status(201).json(ins);
    } else{
        response.status(201).json('No hay artistas nuevos');
    }

})

router.route('/sello/:usr').get(async (request,response)=>{
    console.log(request.params.usr);
    let q = 'SELECT * FROM `sello` WHERE `usr` = \'' + request.params.usr + '\'';
    
    console.log(q);
    
    var result = await pool.query(q);
    console.log(result);

    if (result == []) {
        console.log("esta vacio");
    }
    
    response.status(201).json(result);
   
})


router.route('/discos/inicial').get(async (request,response)=>{
    let respuesta;
    await axios({
        method: 'GET',
        url: conection.api_Master+'/discos'
    }).then(res=>{
        respuesta = res.data;    
    }).catch(err => console.log(err))
    
    //console.log(respuesta.length);
    
    let q = 'INSERT INTO `disco`(`UPC`, `artista_id`, `nombre`) VALUES ';
    console.log(respuesta)
    let c = 0;
    let x = ' ';
    
    for (const element of respuesta) {
        
        c = c + 1;
            
        console.log(element);
        
        let e = remplaced.replaceall('\'', '\\\'',element.ARTIST);
        var res = await pool.query('SELECT `id` FROM `artista` WHERE `nombre` = \''+e+'\'');
        //console.log(res[0].id);
        let a =  remplaced.replaceall('\'', '\\\'',element.ALBUM_NAME);
        q = q + '(\'';
        if (c < respuesta.length) {
            q = q + element.UPC + '\',\'' + res[0].id + '\',\'' + a + '\'),';
            //console.log(q);
        } else {
            q = q + element.UPC + '\',\'' + res[0].id + '\',\'' + a + '\')';
            //console.log(q);
        }
        x = x + ',' + element.UPC;
    }
    //console.log(q);

    var result = await pool.query(q);
    
    response.status(201).json(result);
    
})
router.route('/discos/actualizar').get(async (request,response)=>{
    let respuesta;
    await axios({
        method: 'GET',
        url: conection.api_Master+'/discos'
    }).then(res=>{
        respuesta = res.data;    
    }).catch(err => console.log(err))
    
    console.log(respuesta);
    let a = 'SELECT * FROM `disco`'

    var result = await pool.query(a);
    console.log(result);

    console.log(respuesta.length);
    console.log(result.length);
    let aux = [];
    
    
    if (respuesta.length>result.length) {
        
        result.forEach(el =>{
            aux.push(el.nombre);
        });
        console.log(aux[0]);
        let c = 0;
        let q = 'INSERT INTO `disco`(`UPC`, `artista_id`, `nombre`) VALUES ';
        //console.log(aux.indexOf('CRISTIAN CASTRO & CARLOS MACÍAS'));
        //console.log(aux.indexOf('SONALLI'));
        q = q + '(\'';
        let ins = '';
        for (const ele of respuesta) {
            
            
            //aux.push(ele.ARTIST);
            let i = aux.indexOf(ele.ALBUM_NAME);
            //console.log(i);
            if (i == -1) {
                c = c + 1;
                console.log(ele.ALBUM_NAME);
                
                let e = remplaced.replaceall('\'', '\\\'',ele.ALBUM_NAME);
                if (c < (respuesta.length-result.length)) {
                    ins = ins + ele.ALBUM_NAME + ' , ';
                    q = q + e + '\'),(\'';
                } else {
                    ins = ins + ele.ALBUM_NAME;
                    q = q + e + '\')';
                }
            }

        };
        console.log(q);}/*
        //var res = await pool.query(q);
        response.status(201).json(ins);
    }else if (respuesta.length<result.length) {
        
        respuesta.forEach(el =>{
            aux.push(el.ARTIST);
        });
        
        
        let c = 0;
        let q = 'DELETE FROM `artista` WHERE `nombre` = ';
        console.log(aux.indexOf('CRISTIAN CASTRO & CARLOS MACÍAS'));
        console.log(aux.indexOf('SONALLI'));
        q = q + '\'';
        let ins = '';
        result.forEach(ele => {
            
            
            //aux.push(ele.ARTIST);
            let i = aux.indexOf(ele.nombre);
            //console.log(i);
            if (i == -1) {
                c = c + 1;
                console.log(ele.nombre);
                
                let e = remplaced.replaceall('\'', '\\\'',ele.nombre);
                if (c <= (respuesta.length-result.length)) {
                    ins = ins + ele.nombre + ' , ';
                    q = q + e + '\' or `nombre` = \'';
                } else {
                    ins = ins + ele.nombre;
                    q = q + e + '\'';
                }
            }

        });
        console.log(q);
        //var res = await pool.query(q);
        
        response.status(201).json(ins);
    } else{
        response.status(201).json('No hay artistas nuevos');
    }*/

    response.status(201).json('No hay artistas nuevos');

})

router.route('/canciones/inicial').get(async (request,response)=>{
    let respuesta;
    await axios({
        method: 'GET',
        url: conection.api_Master+'/canciones'
    }).then(res=>{
        respuesta = res.data;    
    }).catch(err => console.log(err))
    
    //console.log(respuesta.length);
    
    let q = 'INSERT INTO `cancion`(`ISRC`, `disco_UPC`, `nombre`) VALUES ';
    console.log(respuesta)
    let c = 0;
    respuesta.forEach(element => {
        c = c + 1;
        q = q + '(\''
        console.log(c);
        console.log(element);
        //let e = element.TRACK_NAME.replace('\'', '\\\'');
        let e = remplaced.replaceall('\'', '\\\'',element.TRACK_NAME);
        if (c < respuesta.length) {
            q = q + element.ISRC + '\',\'' + element.UPC + '\',\'' + e + '\'),';
        } else {
            q = q + element.ISRC + '\',\'' + element.UPC + '\',\'' + e + '\')';
        }
    });
    console.log(q);
    //console.log(c);
    var result = await pool.query(q);
    
    response.status(201).json(result);
   
})

router.route('/regalias/actualizar').get(async (request,response)=>{
    let q = 'SELECT * FROM `sello`';
    //let q = 'SELECT * FROM `sello` ORDER BY `id` DESC';
    var q1 = 'SELECT `s`.`usr`,`a`.`nombre` AS `nombreArtista`,`d`.`UPC`,`d`.`nombre` FROM `sello` AS `s` JOIN `sello_artista` AS `s_a` ON `s`.`id` = `s_a`.`id_sello` JOIN `artista` AS `a` ON `s_a`.`id_artista` = `a`.`id` JOIN `disco` AS `d` ON `d`.`artista_id` = `a`.`id` WHERE `s`.`usr` = BINARY \'';
    let q2 = 'SELECT `s`.`usr`,`a`.`nombre`,`d`.`UPC`,`d`.`nombre`,`c`.`ISRC`,`c`.`nombre` FROM `sello` AS `s` JOIN `sello_artista` AS `s_a` ON `s`.`id` = `s_a`.`id_sello` JOIN `artista` AS `a` ON `s_a`.`id_artista` = `a`.`id` JOIN `disco` AS `d` ON `d`.`artista_id` = `a`.`id` JOIN `cancion` AS `c` ON `d`.`UPC` = `c`.`disco_UPC` WHERE `s`.`usr` = BINARY \'';
    let q3 = 'SELECT DISTINCT `r`.`anio`,`r`.`mes` FROM `sello` AS `s` JOIN `sello_artista` AS `s_a` ON `s`.`id` = `s_a`.`id_sello` JOIN `artista` AS `a` ON `s_a`.`id_artista` = `a`.`id` JOIN `disco` AS `d` ON `d`.`artista_id` = `a`.`id` JOIN `cancion` AS `c` ON `d`.`UPC` = `c`.`disco_UPC` JOIN `regalias` AS `r` ON `c`.`ISRC` = `r`.`cancion_id` WHERE `s`.`usr` = BINARY \'';
    let axx = 'INSERT INTO `regalias`(`cancion_id`, `plataforma`, `clics`, `ingresos`, `anio`, `mes`, `pais`) VALUES ';
    var resta = 1000 * 60 * 60 * 24;
    var calculo = 0;
    var now= new Date();
    var respuesta;
    
    var aux = [];
    var respuesta2;
    var result = await pool.query(q);
    //console.log(result);
    let m = -1;
    let a = 0;
    let f = '';
    //console.log(now);
    calculo = now.getTime() - (resta * (29*2));
    let fecha = new Date(calculo);
    var resu1 = '';
    var fee = now.getFullYear;
    console.log(fecha);
    console.log(fee);
    let am;
    let ay;
    for (let index = 0; index < 12; index++) {
      console.log('-----------------------------------------');
      am = fecha.getMonth()-(index+m);
      ay = fecha.getFullYear()-a;
      console.log(am);
      console.log(ay);
      console.log('-----------------------------------------');
      console.log('-----------------------------------------');
        if(index<11) {
            if (am == 0)
            {
                console.log('es 12');
                m = -13;
                a = 1;
                am = fecha.getMonth()-(index+m);
                ay = fecha.getFullYear()-a;
                f = f + 'f=' + ay +'-'+ am + '&';
                console.log(am);
                console.log(ay);
            }
            else {
                f = f + 'f=' + ay +'-'+ am + '&';
                console.log(am);
                console.log(ay);
            }
        } else {
            if (am == 0)
            {
                console.log('es 12');
                m = -13;
                a = 1; 
                am = fecha.getMonth()-(index+m);
                ay = fecha.getFullYear()-a;
                f = f + 'f=' + ay +'-'+ am;
                console.log(am);
                console.log(ay);
            }
            else {
                f = f + 'f=' + ay +'-'+ am;
                console.log(am);
                console.log(ay);
            }
        }
    }
    
    console.log(f);
    for (const e of result)
    {
        //console.log(q3+e.usr+'\'');
        
        var result1 = await pool.query(q3+e.usr+'\'');
        console.log(result1);
        if(result1.length>0)
        {
            console.log('si tiene registros')
        }else{
            let result1 = await pool.query(q1+e.usr+'\'');
            let UPC = '';
            //console.log(result1);
            
            let c = 0;
            result1.forEach(element => {
                c = c + 1;
                //console.log(element.UPC);
                if (c < result1.length) {
                    UPC = UPC + 'upc=' + element.UPC + '&';
                } else {
                    UPC = UPC + 'upc=' + element.UPC;
                }
            });
            //console.log(UPC);
            
            let result2 = await pool.query(q2+e.usr+'\' ORDER BY `c`.`ISRC` ASC');
            let ISRC = [];
            let ISRC1 = '';
            //console.log(result2);
            let c1 = 0;
            //console.log('-----------------------------------------');
            result2.forEach(element1 => {
                c1 = c1 + 1;
                //console.log(element1);
                ISRC.push(element1.ISRC);
                if (c1 < result2.length) {
                    ISRC1 = ISRC1 + 'isrc=' + element1.ISRC + '&';
                } else {
                    ISRC1 = ISRC1 + 'isrc=' + element1.ISRC;
                }
            });
            console.log(ISRC);
            console.log(ISRC1)
            
            await axios({
                method: 'GET',
                url: conection.api_Master+'/regalia/fecha/upc/isrc?'+UPC+'&'+ISRC1+'&'+f
            }).then(res=>{
                respuesta = res.data;    
            }).catch(err => console.log(err))
            
            let aux = [];
            
            var qi = 'INSERT INTO `regalias`(`cancion_id`, `plataforma`, `clics`, `ingresos`, `anio`, `mes`, `pais`) VALUES ';
            let qx = '';
            let cd = 0;
            let ax = '';
            
            respuesta.forEach(element => {
                //console.log(element);
                ax = aux.find(nombre => nombre.Year_Month === element.Year_Month&&nombre.Retailer === element.Retailer&&nombre.Country_Sale === element.Country_Sale&&nombre.ISRC === element.ISRC);
                 if(ax == undefined){
                    //console.log(ax);
                    if (element.Tipo_de_cambio == null) {
                        element.Tipo_de_cambio = 1;
                        element.Net_Royalty_Total = (element.Net_Royalty_Total*18.5);
                    }else {
                        element.Net_Royalty_Total = (element.Net_Royalty_Total*element.Tipo_de_cambio);
                    }
                    aux.push(element);
                }else {
                    //console.log(ax);
                    if (element.Tipo_de_cambio == null) {
                        element.Tipo_de_cambio = 1;
                        ax.Net_Royalty_Total = ax.Net_Royalty_Total + (element.Net_Royalty_Total*18.5);
                        ax.Quantity = ax.Quantity + element.Quantity;
                    }else {
                        ax.Net_Royalty_Total = ax.Net_Royalty_Total + (element.Net_Royalty_Total*element.Tipo_de_cambio);
                        ax.Quantity = ax.Quantity + element.Quantity;
                    }
                }
            });
            let d = 0;
            for (const element of aux) {
                if (element.Retailer != undefined){
                    console.log("soy el elemento")
                    element.Country_Sale = remplaced.replaceall('\'', '\\\'',element.Country_Sale);
                    console.log(element);
                    if (element.ISRC == null || element.ISRC == '')
                    {
                        element.ISRC = element.UPC;
                        console.log("Es Itunes");
                    }
                    if (element.ISRC == element.UPC)
                    {
                        let l = 'INSERT INTO `cancion` SELECT `UPC`, `UPC`, CONCAT(`nombre`,\'-ALBUM\') FROM `disco` where `UPC` = \''+element.ISRC+'\'';
                        console.log("Es disco");
                        try{
                            resu1 = await pool.query(l);
                        }
                        catch{
                            console.log("Ya existe el registro");
                        }
                        console.log(resu1);
                    }
                    d++;
                    console.log(cd);
                    console.log(d);
                    if (cd < aux.length-1 && d<10000) {
                        qx = qx + '(\'' + element.ISRC + '\',\'' + element.Retailer + '\',' + element.Quantity + ',' + element.Net_Royalty_Total + ',\'' + element.Year_Month + '\',\'0\',\'' + element.Country_Sale + '\'),';
                        console.log("es menor a 1000");
                        //console.log(qx);
                    }else {
                        console.log("1000")
                        qx = qx + '(\'' + element.ISRC + '\',\'' + element.Retailer + '\',' + element.Quantity + ',' + element.Net_Royalty_Total + ',\'' + element.Year_Month + '\',\'0\',\'' + element.Country_Sale + '\')';
                        qi=qi+qx;
                        console.log(qi)
                        resu1 = await pool.query(qi);
                        console.log(resu1);
                        d = 0;
                        qx = '';
                        qi = axx;
                    }  
                }else{
                    console.log(element);
                }
                cd = cd + 1;
            };
            console.log(aux.length);
        }
    }
    response.status(201).json(aux);    
})

router.route('/regalias/:usr').get(verifyToken,async (request,response)=>{
    console.log(request.params.usr);
    console.log(request.headers);
    console.log(request.headers.authorization);
    console.log(request.headers['authorization']);
    let q = 'SELECT `a`.`nombre` AS `nombreArtista`, `d`.`UPC`,`d`.`nombre` AS `nombreDisco`,`c`.`ISRC`,`c`.`nombre` AS `nombreCancion`,`re`.`plataforma`,`re`.`clics`,`re`.`ingresos`,`re`.`anio`,`re`.`mes`,`re`.`pais` FROM `sello` AS `s` JOIN `sello_artista` AS `s_a` ON `s`.`id` = `s_a`.`id_sello` JOIN `artista` AS `a` ON `s_a`.`id_artista` = `a`.`id` JOIN `disco` AS `d` ON `d`.`artista_id` = `a`.`id` JOIN `cancion` AS `c` ON `d`.`UPC` = `c`.`disco_UPC` JOIN `regalias` AS `re` ON `re`.`cancion_id` = `c`.`ISRC` WHERE `s`.`usr` = BINARY \'';
    q = q + request.params.usr + '\'';
    console.log(q);
    
    var result = await pool.query(q);
    console.log(result);

    if (result == []) {
        console.log("esta vacio");
    }
    
    response.status(201).json(result);
   
})

router.route('/regalias/:usr/fecha/').get(verifyToken,async (request,response)=>{
    console.log(request.params.usr);
    console.log(request.query);
    let q = 'SELECT `a`.`nombre` AS `nombreArtista`, `d`.`UPC`,`d`.`nombre` AS `nombreDisco`,`c`.`ISRC`,`c`.`nombre` AS `nombreCancion`,`re`.`plataforma`,`re`.`clics`,`re`.`ingresos`,`re`.`anio`,`re`.`mes`,`re`.`pais` FROM `sello` AS `s` JOIN `sello_artista` AS `s_a` ON `s`.`id` = `s_a`.`id_sello` JOIN `artista` AS `a` ON `s_a`.`id_artista` = `a`.`id` JOIN `disco` AS `d` ON `d`.`artista_id` = `a`.`id` JOIN `cancion` AS `c` ON `d`.`UPC` = `c`.`disco_UPC` JOIN `regalias` AS `re` ON `re`.`cancion_id` = `c`.`ISRC` WHERE `s`.`usr` = BINARY  \'';
    
    q = q + request.params.usr + '\'';
    // and (`re`.`anio`='2021-1' or `re`.`anio`='2020-12' or `re`.`anio`='2020-11')
    let qi = ' and ('
    let c = 0;
    let f = request.query.f;
    try{    

        f.forEach(element => {
            c++;
            if (c<f.length) {
                qi = qi + '`re`.`anio`= \''+element+'\' or ';
            }else {
                qi = qi + '`re`.`anio`= \''+element+'\')';
            }
        
        });
    } catch {
        qi = qi + '`re`.`anio`= \''+f+'\')';
    }
    console.log(q);
    console.log(qi);
    console.log(" ");
    console.log(q+qi);
    var result = await pool.query(q+qi);
    //console.log(result);

    if (result == []) {
        console.log("esta vacio");
    }
    
    response.status(201).json(result);
    //response.status(201).json("si");
   
})


var port = process.env.PORT ||8091;
app.listen(port);
console.log('Order API is rinning at '+ port);
 
/*dboperations.artistas().then(result => {
    console.log(result); 
})*/