/************************************************************************/
/* This file is part of openMask(c) INRIA, CNRS, Universite de Rennes 1 */
/* 1993-2002, thereinafter the Software                                 */
/*                                                                      */
/* The Software has been developped within the Siames Project.          */
/* INRIA, the University of Rennes 1 and CNRS jointly hold intellectual */
/* property rights                                                      */
/*                                                                      */
/* The Software has been registered with the Agence pour la Protection  */
/* des Programmes (APP) under registration number                       */
/* IDDN.FR.001.510008.00.S.P.2001.000.41200                             */
/*                                                                      */
/* This file may be distributed under the terms of the Q Public License */
/* version 1.0 as defined by Trolltech AS of Norway and appearing in    */
/* the file LICENSE.QPL included in the packaging of this file.         */
/*                                                                      */
/* Licensees holding valid specific licenses issued by INRIA, CNRS or   */
/* Universite Rennes 1 for the software may use this file in            */
/* acordance with that specific license                                 */
/************************************************************************/
/************************************************************************/
/* WARNING : GENERATED FILE. DO NOT MODIFY IT.                          */
/* Generated the 2006-09-21 at 15:37:25                                 */
/* Generated by omk version 1.2.0                                       */
/* Use just as it is or derive this class to add the  necessary         */
/* functions.                                                           */
/************************************************************************/
/************************************************************************/

#if !defined _SIMULATED_OBJECTS_OVKPSDUPLICATEDCONTEXTBASE_H_
#define _SIMULATED_OBJECTS_OVKPSDUPLICATEDCONTEXTBASE_H_

#include <PsDuplicatedObject.h>

/** \brief Class \ref PsDuplicatedContextBase generated.
 * \date generated the 2006-09-21 at 15:37:25
 * \author Yann Renard (INRIA/IRISA)
 * @description
 * This class is generated. \n
 * Use it by derivation to add the necessary methods.\n
 * This base class is never implemented, only the derivate classes (like \ref PsDuplicatedContext) are.\n
 * All the members of this class are protected except the destructor according to the OpenMASK precepts.\n
 * @configurationParameters
 *
 * \n \b Configuration \b example
 * \code
 myObject
 {
   Class PsDuplicatedContext
   Scheduling
   {
     Frequency 75
     Process processA
   }
   UserParams
   {

 }
 * \endcode
 */
class PsDuplicatedContextBase : public PsDuplicatedObject
{
	/// @name Constructors and destructor.
	//@{

public:

	/// \brief Destructor of \ref PsDuplicatedContextBase.
	virtual ~PsDuplicatedContextBase() ;

protected:

	/// \brief Protected constructor of \ref PsDuplicatedContextBase call by derivate classes (\ref PsDuplicatedContext).
	PsDuplicatedContextBase( PsController& ctrl, const PsObjectDescriptor& objectDescriptor );
	//@}

	/// @name Reset and loaders
	//@{
	/// \brief Reset the default values of \ref PsDuplicatedContextBase.
	///
	/// No data or output have been declared, this method does nothing.
	virtual void resetDefaultValues();
	/// \brief Configuration parameters loader of \ref PsDuplicatedContextBase.
	/// \param[in] node the root node of the configuration parameter.
	/// \return true if all \e needed parameters can be read.
	///
	/// Reads in the configuration node the values to set the attributs.
	/// No data or output have been declared, this method does nothing.
	virtual bool loadAttributsParameters( const PsConfigurationParameterDescriptor * node );
	/// \brief Configuration parameters loader of \ref PsDuplicatedContextBase.
	/// \param[in] node the root node of the configuration parameter.
	/// \return true if all the inputs are well connected.
	///
	/// Reads in the configuration node the values to connect the inputs.
	/// No input has been declared, this method does nothing.
	virtual bool loadInputsConnectionsParameters( const PsConfigurationParameterDescriptor * node ) { return node ; }
	/// \brief Configuration parameters loader of \ref PsDuplicatedContextBase.
	/// \param[in] node the root node of the configuration parameter.
	/// \return true if all the events are well connected to a signal.
	///
	/// Creates events listeners and associates them to their callback method.\n
	/// Reads in the configuration node the values to register signals.
	/// No event has been declared, this method does nothing.
	virtual bool loadEventsConnectionsParameters( const PsConfigurationParameterDescriptor * node ) { return node ; }
	//@}

	/// @name PsSimulatedObject interfaces
	//@{
	/// \brief Init method inherited from PsSimulatedObject.
	///
	/// Calls the loaders.\n
	/// Most of the time it is not necessary to redefine this method in the children
	/// class. If you have to add some initialisations, redefine and call the
	/// inherited method to load parameters or call directly the loaders.
	virtual void init() ;
	/// \brief Compute method inherited from PsSimulatedObject.
	///
	/// The \ref compute method is splitted in three parts: the first reads the
	/// inputs, the second computes the new values for the parameters, the last
	/// one sets the outputs from their associated parmeters.\n
	/// In the children class, the second method must be defined, and most of
	/// the time you do not have to change the others.\n
	virtual void compute() ;
	/// \brief This part of the \ref compute methods reads the inputs.
	///
	/// No input has been declared, nothing to do in this method.
	virtual void computeInputs() {}
	/// \brief This part of the \ref compute methods computes the parameters.
	///
	/// The inputs and outputs works with associated data, you should use their associated data.\n
	/// It is a pure virtual method, so it must be defined in the children.\n
	/// This method  updates nothing.
	virtual void computeParameters() = 0 ;
	/// \brief This part of the \ref compute methods copies the data in their associated output.
	///
	/// No output has been declared, nothing to do in this method.
	virtual void computeOutputs() {}
	//@}

protected:

	///Flag to know how to handle error during init.
	bool _exitOnInitError ;
	/// @name Data
	//@{

	//@}
	/// @name Inputs, outputs and configuration parameters
	/// The derivated classes must uses the data
	//@{
	//@}
};

#endif // defined _SIMULATED_OBJECTS_OVKPSDUPLICATEDCONTEXTBASE_H_
