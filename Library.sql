-- MySQL dump 10.13  Distrib 5.5.43, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: Library
-- ------------------------------------------------------
-- Server version	5.5.43-0ubuntu0.14.04.1

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
  PRIMARY KEY (`bookId`),
  KEY `borrowedBy` (`borrowedBy`),
  CONSTRAINT `book_ibfk_1` FOREIGN KEY (`borrowedBy`) REFERENCES `user` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1334567891 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES (1204557890,'Hipster Stuff','Fashion','Ian Turnbow',1995,NULL,'0987774321'),(1230057890,'Who Needs Shoes','Life Style','Allen Lunnie',2011,NULL,'0987711321'),(1233557890,'Pierce the Heavens','Romance','Kamina',2000,NULL,'0987754421'),(1234557890,'Party Lacey','Decore','Lacey Hines',2015,NULL,'0987754321'),(1234559890,'What are Drugs','Informative','Trena',1989,NULL,'0987765321'),(1234566890,'The Allen Shrug','Speech','Allen Lunnie',1963,NULL,'0976654321'),(1234567890,'Cookin With Bacon','Cooking','Tahmersu Bacon',1969,NULL,'0987654321'),(1234587890,'Maximum Squats','Sports','Kinder',2014,NULL,'0987744321'),(1244567890,'The Life of Amber','Novel','Bobbi',1849,NULL,'0988654321'),(1266657890,'My Escape','Mystery','Juli Kim',2010,NULL,'0287758321'),(1276558890,'Two Feet Under','Short Story','Ginner Peters',1993,NULL,'0787737321'),(1334567890,'The Best Database Party Ever','Database','Chiang',1999,NULL,'0887654321');
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
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'Tayloe Blabton','1992-08-15','42 Wallaby Way Sydney',0),(2,'Braku Bringhum','2015-05-02','The Corner',1),(3,'Tahmus Fartco','1942-06-12','Normandy Beach',1),(4,'Cucumber Fartcantell','1492-12-02','The Mayflower',0);
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

-- Dump completed on 2015-05-08 23:21:19
