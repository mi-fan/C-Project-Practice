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
-- Table structure for table `tb_book_adjust`
--

DROP TABLE IF EXISTS `tb_book_adjust`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_book_adjust` (
  `adjustcode` int NOT NULL,
  `operator` varchar(45) NOT NULL,
  `take` varchar(45) NOT NULL,
  `store` varchar(45) NOT NULL,
  `barcode` varchar(45) NOT NULL,
  `supplier` varchar(45) NOT NULL,
  `count` int NOT NULL,
  `date` timestamp(6) NOT NULL,
  PRIMARY KEY (`adjustcode`),
  UNIQUE KEY `operator_UNIQUE_adjust` (`operator`),
  UNIQUE KEY `barcode_UNIQUE` (`barcode`),
  UNIQUE KEY `store_UNIQUE` (`store`),
  UNIQUE KEY `supplier_UNIQUE` (`supplier`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_book_adjust`
--

LOCK TABLES `tb_book_adjust` WRITE;
/*!40000 ALTER TABLE `tb_book_adjust` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_book_adjust` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_book_category`
--

DROP TABLE IF EXISTS `tb_book_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_book_category` (
  `category` varchar(45) NOT NULL,
  PRIMARY KEY (`category`),
  UNIQUE KEY `category_UNIQUE` (`category`),
  CONSTRAINT `cat` FOREIGN KEY (`category`) REFERENCES `tb_book_info` (`category`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_book_category`
--

LOCK TABLES `tb_book_category` WRITE;
/*!40000 ALTER TABLE `tb_book_category` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_book_category` ENABLE KEYS */;
UNLOCK TABLES;

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

--
-- Table structure for table `tb_book_input_return`
--

DROP TABLE IF EXISTS `tb_book_input_return`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_book_input_return` (
  `returncode` int NOT NULL,
  `operator` varchar(45) NOT NULL,
  `supplier` varchar(45) NOT NULL,
  `barcode` varchar(45) NOT NULL,
  `time` timestamp(6) NOT NULL,
  `store` varchar(45) NOT NULL,
  `count` int NOT NULL,
  `money` double NOT NULL,
  PRIMARY KEY (`returncode`),
  UNIQUE KEY `operator_UNIQUE_ir` (`operator`),
  UNIQUE KEY `barcode_UNIQUE` (`barcode`),
  UNIQUE KEY `store_UNIQUE` (`store`),
  UNIQUE KEY `supplier_UNIQUE` (`supplier`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_book_input_return`
--

LOCK TABLES `tb_book_input_return` WRITE;
/*!40000 ALTER TABLE `tb_book_input_return` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_book_input_return` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_book_sale`
--

DROP TABLE IF EXISTS `tb_book_sale`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_book_sale` (
  `salecode` int NOT NULL,
  `operator` varchar(45) NOT NULL,
  `barcode` varchar(45) NOT NULL,
  `counter` varchar(45) NOT NULL,
  `customer` varchar(45) NOT NULL,
  `count` int NOT NULL,
  `date` timestamp(6) NOT NULL,
  `money` double NOT NULL,
  PRIMARY KEY (`salecode`),
  UNIQUE KEY `operator_UNIQUE_bs` (`operator`),
  UNIQUE KEY `barcode_UNIQUE` (`barcode`),
  UNIQUE KEY `customer_UNIQUE` (`customer`) /*!80000 INVISIBLE */,
  CONSTRAINT `customer_bs` FOREIGN KEY (`customer`) REFERENCES `tb_book_sale_refund` (`customer`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='			';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_book_sale`
--

LOCK TABLES `tb_book_sale` WRITE;
/*!40000 ALTER TABLE `tb_book_sale` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_book_sale` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_book_sale_refund`
--

DROP TABLE IF EXISTS `tb_book_sale_refund`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_book_sale_refund` (
  `backcode` int NOT NULL,
  `operator` varchar(45) NOT NULL,
  `barcode` varchar(45) NOT NULL,
  `counter` varchar(45) NOT NULL,
  `customer` varchar(45) NOT NULL,
  `count` int NOT NULL,
  `date` timestamp(6) NOT NULL,
  `money` double NOT NULL,
  PRIMARY KEY (`backcode`,`operator`,`barcode`),
  UNIQUE KEY `barcode_UNIQUE` (`barcode`),
  UNIQUE KEY `operator_UNIQUE` (`operator`),
  UNIQUE KEY `customer_UNIQUE` (`customer`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_book_sale_refund`
--

LOCK TABLES `tb_book_sale_refund` WRITE;
/*!40000 ALTER TABLE `tb_book_sale_refund` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_book_sale_refund` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_counter`
--

DROP TABLE IF EXISTS `tb_counter`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_counter` (
  `name` varchar(45) NOT NULL,
  PRIMARY KEY (`name`),
  UNIQUE KEY `name_UNIQUE_counter` (`name`) /*!80000 INVISIBLE */,
  CONSTRAINT `name` FOREIGN KEY (`name`) REFERENCES `tb_operator` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_counter`
--

LOCK TABLES `tb_counter` WRITE;
/*!40000 ALTER TABLE `tb_counter` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_counter` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_operator`
--

DROP TABLE IF EXISTS `tb_operator`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_operator` (
  `name` varchar(45) NOT NULL,
  `password` varchar(45) NOT NULL,
  `level` int NOT NULL,
  UNIQUE KEY `name_UNIQUE` (`name`),
  CONSTRAINT `name1` FOREIGN KEY (`name`) REFERENCES `tb_counter` (`name`),
  CONSTRAINT `operator1` FOREIGN KEY (`name`) REFERENCES `tb_book_sale_refund` (`operator`),
  CONSTRAINT `operator2` FOREIGN KEY (`name`) REFERENCES `tb_book_sale` (`operator`),
  CONSTRAINT `operator3` FOREIGN KEY (`name`) REFERENCES `tb_book_adjust` (`operator`),
  CONSTRAINT `operator4` FOREIGN KEY (`name`) REFERENCES `tb_book_input_return` (`operator`),
  CONSTRAINT `operator5` FOREIGN KEY (`name`) REFERENCES `tb_book_input` (`operator`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_operator`
--

LOCK TABLES `tb_operator` WRITE;
/*!40000 ALTER TABLE `tb_operator` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_operator` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_stock_info`
--

DROP TABLE IF EXISTS `tb_stock_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_stock_info` (
  `barcode` varchar(25) NOT NULL,
  `store` varchar(45) NOT NULL,
  `stock` int NOT NULL,
  PRIMARY KEY (`barcode`),
  UNIQUE KEY `barcode_UNIQUE` (`barcode`),
  UNIQUE KEY `store_UNIQUE` (`store`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_stock_info`
--

LOCK TABLES `tb_stock_info` WRITE;
/*!40000 ALTER TABLE `tb_stock_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_stock_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_store_info`
--

DROP TABLE IF EXISTS `tb_store_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_store_info` (
  `storename` varchar(25) NOT NULL,
  PRIMARY KEY (`storename`),
  UNIQUE KEY `storename_UNIQUE` (`storename`),
  CONSTRAINT `store1` FOREIGN KEY (`storename`) REFERENCES `tb_book_input` (`store`),
  CONSTRAINT `store2` FOREIGN KEY (`storename`) REFERENCES `tb_book_input_return` (`store`),
  CONSTRAINT `store3` FOREIGN KEY (`storename`) REFERENCES `tb_book_adjust` (`store`),
  CONSTRAINT `store_main` FOREIGN KEY (`storename`) REFERENCES `tb_stock_info` (`store`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_store_info`
--

LOCK TABLES `tb_store_info` WRITE;
/*!40000 ALTER TABLE `tb_store_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_store_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tb_supplier_info`
--

DROP TABLE IF EXISTS `tb_supplier_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tb_supplier_info` (
  `name` varchar(25) NOT NULL,
  `corporation` varchar(25) NOT NULL,
  `principal` varchar(25) NOT NULL,
  `phone` varchar(25) NOT NULL,
  `address` varchar(25) NOT NULL,
  `website` varchar(45) NOT NULL,
  `e_mail` varchar(25) NOT NULL,
  UNIQUE KEY `name_UNIQUE` (`name`),
  CONSTRAINT `supplier1` FOREIGN KEY (`name`) REFERENCES `tb_book_input_return` (`supplier`),
  CONSTRAINT `supplier2` FOREIGN KEY (`name`) REFERENCES `tb_book_input` (`supplier`),
  CONSTRAINT `supplier3` FOREIGN KEY (`name`) REFERENCES `tb_book_adjust` (`supplier`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tb_supplier_info`
--

LOCK TABLES `tb_supplier_info` WRITE;
/*!40000 ALTER TABLE `tb_supplier_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `tb_supplier_info` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-05 17:01:02
