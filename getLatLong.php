
<?php

	require "/includes/class.Listing.inc";
  require "/includes/class.DB.inc"; 
  /*Not that any addresses that have special characters can cause an issue with the response that Google sends, placing the markers at strange positions. 
  Remove all special characters from the address before running this script. */
    $i = 0;

						            $db = DB::getInstance();
                        $mysqli = $db->getConnection();
                        $sql_q = "SELECT * FROM TABLE_NAME WHERE Lat = ''";
                        $list = mysqli_query($mysqli, $sql_q);
                      
                        while($row = $list->fetch_assoc()){
                          if( $i < 500){

                                $listing = new Listing(array(
                                  'prime'   =>$row["prime"],
                                  'address' =>$row["address"],
                                  'state'   =>$row["state"],
                                  'lat'     =>$row["lat"],
                                  'long'    =>$row["lng"],
                                  ));
                                
                                 $i++;

                                $listing->setLatLong();
                              }

                      }//end while loop



?>



