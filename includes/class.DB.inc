<?php
//DB, only one connection allowed
class DB{
	private $_connection;
	private static $_instance;
	
	
	//get an instance of the DB, return type DB
	public static function getInstance(){
		if(!self::$_instance){
			self::$_instance = new self();
		}
		return self::$_instance; 
	}
//define constructor for the DB object

	public function __construct(){
		$this->_connection = new mysqli('server', 'user', 'password', 'database');	
		//error handling
		if(mysqli_connect_error()){
			trigger_error("Failed to connect to DB ". mysqli_connect_error(), E_USER_ERROR);
		}
	}
	
	//empty clone magic method to prevent duplication
	private function __clone(){}
	
	//get mysqli connection
	public function getConnection(){
		return $this->_connection;
	}
}

?>