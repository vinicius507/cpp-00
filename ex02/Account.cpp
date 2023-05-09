/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:04:50 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/05/08 21:37:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  this->_amount = initial_deposit;
  this->_accountIndex = Account::_nbAccounts++;
  Account::_totalAmount += initial_deposit;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;
}

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
};

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts()
            << ";total:" << Account::getTotalAmount()
            << ";deposits:" << Account::getNbDeposits()
            << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal > this->_amount) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:refused";
    return (false);
  }

  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  Account::_totalNbWithdrawals++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount + withdrawal
            << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals;
  return (true);
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::displayStatus() const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  char buf[19] = {'\0'};
  time_t now = time(NULL);

  strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localtime(&now));
  std::cout << buf;
}
