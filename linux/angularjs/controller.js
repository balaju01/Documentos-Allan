var app = angular.module("MiprimerApp",[]);
app.controller("PrimerControlador",function($scope){
	$scope.nuecoCom={};
	$scope.nombre="Allan Ulises";
	$scope.comentarios=[
		{
			comentario: "Ta chido",
			username: "El tunas"
		},
		{
			comentario: "Ta chido carnalaso",
			username: "El ñero"
		}
	];
	$scope.agregarComentario=function(){
		$scope.comentarios.push($scope.nuecoCom);
		$scope.nuecoCom={};
	};
});