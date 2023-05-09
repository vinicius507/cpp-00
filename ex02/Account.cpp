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

void Account::_displayTimestamp(void) {
  char buf[19] = {'\0'};
  time_t now = time(NULL);

  strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", localtime(&now));
  std::cout << buf;
}
