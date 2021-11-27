// File name:GuitarString.cpp
// // Author:Solomon Hearn
// userid:hearnsd
// Email:solomon.d.hearn@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
// Description: Guitar string function implementation.
//Functions include pluck, tic, getTime, getFrequency, and sample
// Honor statement: I pledge that I did not give or receive any unauthorized aid on this assignment.
// Last Changed: November 2, 2021

#include "GuitarString.h"
#include <chrono>
#include <random>
#include <iostream>


//create a ring buffer of the desired capacity
//N (sampling rate divided by frequency, rounded to the nearest integer) by
//initializing a queue and filling the queue to represent a guitar string at rest by
//enqueueing N zeros. [Note: you may assume that the frequency parameter will always
//be in the range of human hearing, and thus N will always be greater than one, and
//thus the Karplus-Strong algorithm will always work.]

// The constructor for a string of the given frequency.
// pre: frequency is positive.
// post: object is initialized to represent a string at rest.
// Throws a std::invalid_argument exception if the frequency is not positive.

GuitarString::GuitarString(double frequency) : ticCount(0), frequency(frequency) {
    if (frequency > 0) {
        for (int i = 0; i < round(SAMPLE_RATE/frequency); i++) {
            d.enqueue(0);
        }
    } else {
        throw std::invalid_argument("Frequency is not positive");
    }
}

// Pluck the string.
// post: replaced all elements in the ring buffer with the same number of
// random values between -0.5 and +0.5

void GuitarString::pluck() {
    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);
    for (size_t i = 0; i < d.size(); i++) {
        double num = distribution(generator);
        d.dequeue();
        d.enqueue(num);
    }

}

// Tic the clock by advancing the simulation one step.
// post: the Karplus-Strong update has been applied to the string.
void GuitarString::tic() {
    double karplus = d.front();
    d.dequeue();
    d.enqueue(((karplus + d.front()) / 2) * DECAY_FACTOR);
    ticCount++;
}

// Return the current sound sample of the string.
double GuitarString::sample() const {
    return d.front();
}

// Return the number of time steps executed == number of calls to ticCount().
size_t GuitarString::getTime() const {
    return ticCount;
}

// Return the frequency of the string.
double GuitarString::getFrequency() const {
    return frequency;

}