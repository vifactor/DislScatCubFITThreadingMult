/*
 * FitANACalculatorSkewDouble.h
 *
 *  Created on: 24 july 2014
 *      Author: kopp
 */

#ifndef FITANACALCULATORSKEWDOUBLE_H_
#define FITANACALCULATORSKEWDOUBLE_H_

#include "ANACalculatorSkewDouble.h"
#include "NonlinearFit.h"
#include <boost/lexical_cast.hpp>

class ANACalculatorCoplanarTripleArgument : public NonlinearFit::CalculatorArgument
{
public:
	ANACalculatorCoplanarTripleArgument(double qx, double qz, int id)
	{
	    m_qx = qx; m_qz = qz;
	    m_id = id;
	}
	virtual ~ANACalculatorCoplanarTripleArgument() {}
	
	double m_qx, m_qz;
	int m_id;
};

class FitANACalculatorCoplanarTriple:
		public NonlinearFit::FitCalculator
{
public:
	FitANACalculatorCoplanarTriple(
	        const std::vector<ANACalculatorSkewDouble *>& calculators);
	virtual ~FitANACalculatorCoplanarTriple() {}
	virtual void reinit(const NonlinearFit::CalculatorParameterMap& params);
	virtual double eval(const NonlinearFit::CalculatorArgument * arg);
protected:
	std::vector<ANACalculatorSkewDouble *> m_calculators;
	std::vector<double> m_scales, m_backgrounds;
	std::vector<std::string> m_scale_names,
	                         m_background_names,
	                         m_th_density_names,
	                         m_th_rc_names;
	
	void initParameterNames(size_t nblayers);
};

#endif /* FITANACALCULATORSKEWDOUBLE_H_ */
