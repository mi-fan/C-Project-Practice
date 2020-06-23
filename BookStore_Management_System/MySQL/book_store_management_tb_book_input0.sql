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
-- Table structure for table `tb_book_input`
--

DROP TABLE IF EXISTS `tb_book_input`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_book_input` (
  `inputcode` int NOT NULL,
  `operator` varchar(45) DEFAULT NULL,
  `supplier` varchar(45) DEFAULT NULL,
  `barcode` varchar(45) DEFAULT NULL,
  `time` timestamp(6) NULL DEFAULT NULL,
  `store` varchar(45) DEFAULT NULL,
  `count` int DEFAULT NULL,
  `money` double DEFAULT NULL,
  PRIMARY KEY (`inputcode`),
  UNIQUE KEY `inputcode_UNIQUE` (`inputcode`),
  UNIQUE KEY `money_UNIQUE` (`money`),
  UNIQUE KEY `count_UNIQUE` (`count`),
  UNIQUE KEY `store_UNIQUE` (`store`),
  UNIQUE KEY `time_UNIQUE` (`time`),
  UNIQUE KEY `barcode_UNIQUE` (`barcode`),
  UNIQUE KEY `supplier_UNIQUE` (`supplier`),
  UNIQUE KEY `operator_UNIQUE_input` (`operator`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_book_input`
--

LOCK TABLES `tb_book_input` WRITE;
/*!40000 ALTER TABLE `tb_book_input` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_book_input` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-06-23 21:47:11
