/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:04:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/09 08:21:52 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
  this->_accountIndex = getNbAccounts();
  this->_amount = 0;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  _nbAccounts++;

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "created" << std::endl;
}

Account::Account(int initial_deposit) {
  this->_accountIndex = getNbAccounts();
  this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  _nbAccounts++;
  _totalAmount += initial_deposit;

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "created" << std::endl;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "closed" << std::endl;
};

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";"
            << "total:" << getTotalAmount() << ";"
            << "deposits:" << getNbDeposits() << ";"
            << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
  this->_amount += deposit;
  this->_nbDeposits++;

  _totalAmount += deposit;
  _totalNbDeposits++;

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "p_amount:" << this->_amount - deposit << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << this->_amount << ";"
            << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal > this->_amount) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << this->_amount << ";"
              << "withdrawal:refused" << std::endl;
    return (false);
  }

  this->_amount -= withdrawal;
  this->_nbWithdrawals++;

  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "p_amount:" << this->_amount + withdrawal << ";"
            << "withdrawal:" << withdrawal << ";"
            << "amount:" << this->_amount << ";"
            << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return (true);
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "deposits:" << this->_nbDeposits << ";"
            << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  char buf[19] = {'\0'};
  time_t now = time(NULL);

  strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localtime(&now));
  std::cout << buf;
}
