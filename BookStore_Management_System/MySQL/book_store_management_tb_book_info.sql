-- MySQL dump 10.13  Distrib 8.0.20, for Win64 (x86_64)
--
-- Host: localhost    Database: book_store_management
-- ------------------------------------------------------
-- Server version	8.0.20

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `tb_book_info`
--

DROP TABLE IF EXISTS `tb_book_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_book_info` (
  `barcode` varchar(45) NOT NULL,
  `bookname` varchar(45) NOT NULL,
  `easymark` varchar(45) NOT NULL,
  `author` varchar(45) NOT NULL,
  `publisher` varchar(45) NOT NULL,
  `note` varchar(45) NOT NULL,
  `category` varchar(45) NOT NULL,
  `price` double NOT NULL,
  PRIMARY KEY (`barcode`),
  UNIQUE KEY `category_UNIQUE` (`category`),
  CONSTRAINT `bar1` FOREIGN KEY (`barcode`) REFERENCES `tb_stock_info` (`barcode`),
  CONSTRAINT `bar2` FOREIGN KEY (`barcode`) REFERENCES `tb_book_sale_refund` (`barcode`),
  CONSTRAINT `bar3` FOREIGN KEY (`barcode`) REFERENCES `tb_book_sale` (`barcode`),
  CONSTRAINT `bar4` FOREIGN KEY (`barcode`) REFERENCES `tb_book_adjust` (`barcode`),
  CONSTRAINT `bar5` FOREIGN KEY (`barcode`) REFERENCES `tb_book_input_return` (`barcode`),
  CONSTRAINT `bar6` FOREIGN KEY (`barcode`) REFERENCES `tb_book_input` (`barcode`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_book_info`
--

LOCK TABLES `tb_book_info` WRITE;
/*!40000 ALTER TABLE `tb_book_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_book_info` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-05 16:57:41
