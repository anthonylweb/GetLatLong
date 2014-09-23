<?php
//Listing Class

class Listing{
	//DEFINE VARIABLES
	const IMG_PATH = "img/";
	const KEY = 'GeoCodeKey';//This is for the GeoCode script

	private $prime;
	public $address;
	public $state;
	public $lat;
	public $long;
	public $curLat = '';
    public $curLong = '';

	//CONSTRUCTOR FUNCTION

	function __construct($data = array()){

		if($data){
	        foreach($data as $name => $value){
	            $this->$name = $value;
	        }
	    }		
	}


	private function getLocation($url){
        $jsonData   = file_get_contents($url);
        $data = json_decode($jsonData, true);
         

       if($data['status']!='OK'){            
            echo $jsonData;
           return;
        }else{
            $this->curLat = $data['results'][0]['geometry']['location']['lat'];
            $this->curLong = $data['results'][0]['geometry']['location']['lng'];
        }
    }

	public function setLatLong(){
					 	
				
                    $staddress = str_replace(" ", "+", $this->address);
                    $url = "https://maps.googleapis.com/maps/api/geocode/json?address=".$staddress."+".$this->state."&key=".self::KEY;

                   	$this->getLocation($url);

                    $db = DB::getInstance();
                    $mysqli = $db->getConnection();
                    $sql = "UPDATE address SET Lat = '$this->curLat' , Lng = '$this->curLong' WHERE prime = $this->prime"; 
                   	$result = mysqli_query($mysqli, $sql);
					if($result){
						echo "Success!!<br>";
					} else{
						echo "<br>Failed!!  ". $mysqli->error ."<br>";
					}
				
	}

	 

}// end Listing class

?>