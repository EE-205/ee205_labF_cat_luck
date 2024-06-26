///////////////////////////////////////////////////////////////////////////////
//  University of Hawaii, College of Engineering
//  Lab D - Lucky Cat - EE 205 (Object Oriented Programming) - Spr 2024
//
//  Cats make their own luck
//
/// Declare the Draw class
///
/// @file   Draw.h
/// @author TODO <TODO@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <climits>    // For UCHAR_MAX
#include <cstdint>    // For uint8_t uint64_t

#include "config.h"   // For application configuration


/// Represents one Draw in a Game
///
/// A Draw may be one of many tickets purchased by customers or it may be the
/// one winning Draw of the Game
class Draw {
private:  // /////////////////////// Private Members ///////////////////////////
   const Game& game;  ///< The Game associated with this Draw


protected:  // //////////////////// Protected Members //////////////////////////
   /// The sorted set of numbers in the Draw
   ///
   /// These are protected, so unit tests can derive and set them
   ///
   /// @todo In retrospect, I regret this data structure.  It wastes a ton
   ///       of space when this scales up.  Next time, I'll do it with a
   ///       bitfield or linked list (something that better matches the
   ///       entropy of each Draw).
   union alignas( 8 ) {
      uint8_t  each[ MAX_DRAWS   ];  ///< Each individual Draw
      uint64_t   g8[ MAX_DRAWS/8 ];  ///< A group of 8 Draws
   } draw;  ///< The sorted set of numbers in the Draw


public:  // ///////////////////////// Static Methods ///////////////////////////
   static bool    validate_static();
   static uint8_t getRandom8( uint8_t balls );


public:  // /////////////////// Constructors & Destructors /////////////////////
   Draw( const Draw& rhs_draw );  // Copy constructor
   Draw( const Game& newGame );


public:  // ///////////////////////// Public Methods ///////////////////////////
   bool validate() const;
   void dump()     const;


public:  // /////////////////////// Operator Overrides /////////////////////////
   Draw& operator = ( const Draw& rhs_draw );
   bool operator == ( const Draw& rhs_draw ) const;
   bool operator != ( const Draw& rhs_draw ) const;
   bool operator <  ( const Draw& rhs_draw ) const;
// bool operator <= ( const Draw& rhs_draw ) const;
// bool operator >  ( const Draw& rhs_draw ) const;
// bool operator >= ( const Draw& rhs_draw ) const;

};
