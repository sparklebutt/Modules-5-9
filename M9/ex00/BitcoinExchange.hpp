/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaboom <shaboom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:05:48 by shaboom           #+#    #+#             */
/*   Updated: 2025/02/04 10:29:54 by shaboom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream> //main
#include <string> //main
#include <unordered_map>
#include <list>
/**
 * @brief use ofunordered_map : faster look up, order does not matter in the in
 * the context of this project , since all key values(dates) will be unique, 
 * i do not have to make my own collision handeling for the hash table, unordered unordered_map
 * has its own that should suffice here.
 * 
 * @example of a custom hasher function to prevent hash collisions
 * struct CustomHash {
    size_t operator()(const std::string& key) const {
        size_t hash = 0;
        for (char ch : key) {
            hash = hash * 31 + ch;
        }
        return hash;
    
 */
class BitcoinExchange
{
	private:
		unsigned int m_listLength = 0;
		std::unordered_map<std::string, double> m_exchangeRates;
		std::unordered_map<std::string, double> m_evaluationSheet;
		void readTounordered_map(const std::string& filename, std::unordered_map<std::string, double>& unordered_map, char delim);
		//create a file
		void findMatchingKeys();
		void printCalculation(double frate, double ammount);
		void adjustLength(char op);
		//compare key values (dates) both unordered_maps
		//calculate exchnage rate key values (dates) 
		

	public:
		BitcoinExchange ();
		BitcoinExchange (const std::string& rates, const std::string& conversions);
		BitcoinExchange (BitcoinExchange &other) = delete;
		BitcoinExchange& operator=(BitcoinExchange &other) = delete;
		~BitcoinExchange ();
		
		unsigned int getevalLength() const;
		void showValues();

		
		
};