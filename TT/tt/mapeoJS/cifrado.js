var semilla="";

for (var i = 0; i < 5; i++) {
	var r = Math.floor((Math.random() * 63) + 1);
	semilla=semilla + ItoC(r);
}

alert(semilla);

var shaObj = new jsSHA("SHA-1", "TEXT");
shaObj.update(semilla);
var hash = shaObj.getHash("HEX");

alert(hash);
var llave;
llave = hash[0];
//llave = llave + hash[1];
for (var i = 1; i < 16; i++) {
	llave=llave + String(hash[i]);
}

alert(String(llave));

usedKey=llave;
myStr="Osama Oransa2012Osama Oransa2011RashaOsama Oransa2012Osa  Oransa2011RashaOsama Oransa2012Osama Oransa2011RashaOsama Oransa2012Osama Oransa2011Rasha";
alert(myStr);

var key=init(usedKey);
alert(key);
encrypted=encryptLongString(myStr,key);
alert('after encrypt='+encrypted);
decrypted=decryptLongString(encrypted,key);
alert('after decrypt='+decrypted);
finish();


