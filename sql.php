<?php
if ($_GET["token"] == "token1234"){
$temp = 0;
$temp = $_GET["temp"];

$servername = "SERVER HOST";
$username = "USERNAME";
$password = "PASSWORD";
$dbname = "DATABASRE";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "INSERT INTO test (id)
VALUES ('" . $temp . "')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
} else {
    echo "Access denied.";
}
?>
