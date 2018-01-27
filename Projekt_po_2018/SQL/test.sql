-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Czas generowania: 24 Sty 2018, 21:24
-- Wersja serwera: 10.1.13-MariaDB
-- Wersja PHP: 5.6.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `test`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `kienci`
--

CREATE TABLE `kienci` (
  `id_klienta` int(11) NOT NULL,
  `Imie` varchar(30) COLLATE utf8_polish_ci NOT NULL,
  `Nazwisko` varchar(30) COLLATE utf8_polish_ci NOT NULL,
  `AdresZamieszkania` text COLLATE utf8_polish_ci NOT NULL,
  `NrTel` int(11) NOT NULL,
  `EMail` varchar(30) COLLATE utf8_polish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

--
-- Zrzut danych tabeli `kienci`
--

INSERT INTO `kienci` (`id_klienta`, `Imie`, `Nazwisko`, `AdresZamieszkania`, `NrTel`, `EMail`) VALUES
(1, 'Arek', 'Furtka', 'Gliwice Domańskiego 2/1', 666999888, 'a.furtka@gmail.com');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indexes for table `kienci`
--
ALTER TABLE `kienci`
  ADD PRIMARY KEY (`id_klienta`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `kienci`
--
ALTER TABLE `kienci`
  MODIFY `id_klienta` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
