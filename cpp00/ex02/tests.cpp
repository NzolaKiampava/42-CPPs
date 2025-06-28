// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;   // is a type for a vector of Account objects
	typedef std::vector<int>								  ints_t;		// is a type for a vector of integers
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;	// is a type for a pair of iterators (one for accounts vector, one for integers vector)

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };	// create an array of initial deposit amounts
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );				// creates a vector of Account objects using these amounts
	accounts_t				accounts( amounts, amounts + amounts_size );				// Each amount will create a new Account with that initial deposit
	accounts_t::iterator	acc_begin	= accounts.begin();								 
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };	// create an array of deposit amounts
	size_t const		d_size( sizeof(d) / sizeof(int) );					// converts it to a vecto of integers for deposits
	ints_t				deposits( d, d + d_size );							// setting up withdrawls
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };	// create an array of withdrawal amount
	size_t const		w_size( sizeof(w) / sizeof(int) );						// converts it to a vector of integers for withdrawals
	ints_t				withdrawals( w, w + w_size );							// the main test sequence
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	// Display initial state
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Make all deposits
	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	// Show state after deposit
	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	// Make all withdrawals
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
