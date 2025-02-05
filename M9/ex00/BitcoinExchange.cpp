/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:58:06 by shaboom           #+#    #+#             */
/*   Updated: 2025/01/29 12:07:46 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream> //file
#include <sstream> //?
BitcoinExchange::BitcoinExchange () : m_exchangeRates(), m_evaluationSheet(){
	std::cout<<"constructor called\n";
}

BitcoinExchange::BitcoinExchange(const std::string& rates, const std::string& conversions) : BitcoinExchange()  {

	std::cout<<"set up constructor called\n";
	readTounordered_map(rates, m_exchangeRates, ',');
	readTounordered_map(conversions, m_evaluationSheet, '|');
	//findMatchingKeys();
}//m_exchangeRates(), m_evaluationSheet()

/*BitcoinExchange::BitcoinExchange (BitcoinExchange &other) {
	std::cout<<"copy constructor called\n";
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &other) {
	std::cout<<"assignment operator called\n";
	if (this != &other)
	{

	}

}*/
BitcoinExchange::~BitcoinExchange () {std::cout<<"destructor called\n";}

unsigned int BitcoinExchange::getevalLength() const
{
	return m_listLength;
}

void BitcoinExchange::readTounordered_map(const std::string& filename, std::unordered_map<std::string, double>& unordered_map, char delim)
{
	bool header = true;
	std::string line, date;

	std::ifstream file(filename);
	if (!file)
		throw std::runtime_error(filename + "error "); // file could not be found or opened
	while (std::getline(file, line))
	{
		double value;
		if (header)
		{
			// skip the first line
			header = false;
			continue ;
		}
		std::stringstream seperator(line);
		if(!std::getline(seperator, date, delim)) // getline leavse the pointer at the first char after the first  ','
			throw std::runtime_error("date input incorrect or missing comma : ");
        date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
        date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
		//seperator >> value;
		if (!(seperator >> value)) // stream converts for us 
			throw std::runtime_error("value missing or no value applied : ");
		unordered_map[date] = value;
		//unordered_map.insert(std::make_pair(date, value));
		if (delim == '|')
		{

			std::cout << "Inserting into unordered_map: " << date << " -> " << value << std::endl;
			adjustLength('+');
			//std::cout<<"should print twice \n";
		}

	}
 std::cout << "Final size of unordered_map after population: ----------------------" << unordered_map.size() << std::endl;
}

void BitcoinExchange::findMatchingKeys() {
//date);
	int i = 0;
	std::unordered_map<std::string, double>::iterator it = m_evaluationSheet.begin();
	 std::cout << "Size of m_evaluationSheet: " << m_evaluationSheet.size()<<std::endl;
	std::cout << "Size of m_exchangerates: " << m_exchangeRates.size()<<std::endl;
	std::cout<<"wwweeeeeeeeeeeee"<<getevalLength()<<"\n";
	std::cout<<"first value should be 3 " <<it->second<<"\n"; //this is onlt printing once

		while (it != m_evaluationSheet.end())
		{
			std::cout<<"should print tthrice loo in it" <<it->second<<"\n"; //this is onlt printing once
			std::unordered_map<std::string, double>::const_iterator rateIt = m_exchangeRates.find(it->first);
			//std::cout<<rateIt->second<< it->second<<"are these correct now\n";
			std::cout<<"calc "<<i<<" = "; printCalculation(rateIt->second, it->second);
			it++;
			i++; // never gets to 3 as it should , only 0
		}
		//adjustLength('-');

}
void BitcoinExchange::printCalculation(double rate, double ammount)
{
	std::cout<<"show me rate = "<<rate<<"show me ammount ="<<ammount <<std::endl;
	if (ammount <= -1)
		std::cout<<"ERROR: number can not me miunus "<<std::endl;
	else if (rate == 0)
		std::cout<<0<<std::endl;
	else
		std::cout<<ammount * rate<<std::endl;
}
void BitcoinExchange::adjustLength(char op)
{
	switch (op)
	{
		case '+':
			++m_listLength;
			break ;
		case '-':
			if (m_listLength > 0)
			{
				--m_listLength;
			}
			break;
		default:
			throw std::runtime_error("Invalid operation");
            break;
	}
}
void BitcoinExchange::showValues()
{
	findMatchingKeys();
}
