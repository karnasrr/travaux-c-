--
-- Base de données: `maBase`
--

CREATE DATABASE IF NOT EXISTS `maBase`;

USE `maBase`;

-- --------------------------------------------------------

CREATE TABLE IF NOT EXISTS `mesures` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `heure` time NOT NULL,
  `temperature` float NOT NULL,
  PRIMARY KEY (`id`)
);

INSERT INTO `mesures` (`id`, `date`, `heure`, `temperature`) VALUES
(1, '2009-09-08', '08:00:00', 35.23),
(2, '2009-09-08', '08:01:00', 35.1),
(3, '2009-09-08', '08:02:00', 34.45),
(4, '2009-09-08', '08:03:00', 35.02),
(5, '2009-09-08', '08:04:00', 35.53),
(6, '2009-09-09', '08:00:00', 35.23),
(7, '2009-09-09', '08:01:00', 35.1),
(8, '2009-09-09', '08:02:00', 34.45),
(9, '2009-09-09', '08:03:00', 35.02),
(10, '2009-09-09', '08:04:00', 35.53),
(11, '2009-09-09', '08:05:00', 35.12);

CREATE TABLE IF NOT EXISTS `parametres` (
  `periode` int(10) NOT NULL
);

INSERT INTO `parametres` (`periode`) VALUES
(1000);

CREATE TABLE IF NOT EXISTS `seuils` (
  `min` float NOT NULL,
  `max` float NOT NULL
);

INSERT INTO `seuils` (`min`, `max`) VALUES
(35.0, 35.5);
