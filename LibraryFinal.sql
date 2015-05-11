CREATE DATABASE  IF NOT EXISTS `library` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `library`;
-- MySQL dump 10.13  Distrib 5.6.23, for Win64 (x86_64)
--
-- Host: localhost    Database: library
-- ------------------------------------------------------
-- Server version	5.6.23-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `book` (
  `bookId` int(10) NOT NULL AUTO_INCREMENT,
  `title` varchar(35) NOT NULL,
  `subject` varchar(35) NOT NULL,
  `author` varchar(35) DEFAULT NULL,
  `year` int(4) DEFAULT NULL,
  `borrowedBy` int(10) DEFAULT NULL,
  `isbn` varchar(10) DEFAULT NULL,
  `lastBorrowedBy` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`bookId`),
  KEY `borrowedBy` (`borrowedBy`),
  CONSTRAINT `book_ibfk_1` FOREIGN KEY (`borrowedBy`) REFERENCES `user` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES (1,'Hipster Stuff','Fashion','Ian Turnbow',1995,1,'0987774321','3'),(2,'Who Needs Shoes','Life Style','Allen Lunnie',2011,1,'0987711321',NULL),(3,'Pierce the Heavens','Romance','Kamina',2000,1,'0987754421','1'),(4,'Party Lacey','Decore','Lacey Hines',2015,1,'0987754321',NULL),(5,'What are Drugs','Informative','Trena',1989,1,'0987765321',NULL),(6,'The Allen Shrug','Speech','Allen Lunnie',1963,1,'0976654321',NULL),(7,'Cookin With Bacon','Cooking','Tahmersu Bacon',1969,1,'0987654321',NULL),(8,'Maximum Squats','Sports','Kinder',2014,1,'0987744321',NULL),(9,'The Life of Amber','Novel','Bobbi',1849,1,'0988654321',NULL),(10,'My Escape','Mystery','Juli Kim',2010,1,'0287758321','1'),(11,'Two Feet Under','Short Story','Ginner Peters',1993,3,'0787737321','1'),(12,'The Best Database Party Ever','Database','Chiang',1999,NULL,'0887654321','1'),(13,'Life Style Book Two','Life Style','Allen Lunnie',2105,NULL,'123456789',NULL),(16,'test','test','test',1992,NULL,'0000000000',NULL);
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(35) NOT NULL,
  `dob` date DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `isStaff` tinyint(1) DEFAULT NULL,
  `numCheckedOut` int(11) DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'Tayloe Blabton','1992-08-15','42 Wallaby Way Sydney',0,10),(2,'Braku Bringhum','2015-05-02','The Sticks',1,0),(3,'Tahmus Fartco','1942-06-12','Normandy Beach',1,1),(4,'Cucumber Fartcantell','1492-12-02','The Mayflower',0,0);
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-05-11 13:20:48
