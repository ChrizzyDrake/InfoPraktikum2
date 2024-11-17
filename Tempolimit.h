/*
 * Tempolimit.h
 *
 *  Created on: 09.11.2024
 *      Author: User
 */

#ifndef TEMPOLIMIT_H_
#define TEMPOLIMIT_H_

#include <limits>

enum class Tempolimit
{
	Innerorts = 50,
	Landstraße = 100,
	Autobahn = std::numeric_limits<int>::max()
};



#endif /* TEMPOLIMIT_H_ */
