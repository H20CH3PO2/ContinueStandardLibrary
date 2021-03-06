#pragma once
#include "pch.h"
/*
*	GraphAdjacencyList.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/
#include "../Sequence/ListSequence.hpp"
namespace csl {

template<class T>
class GraphAdjacencyList
{
    typedef ListSequence<T> List;
    ListSequence<List> AdjacencyList;
public:
    GraphAdjacencyList();
    GraphAdjacencyList(const GraphAdjacencyList&);
    GraphAdjacencyList(GraphAdjacencyList&&);
    GraphAdjacencyList(ListSequence<List>);
    ~GraphAdjacencyList();
public:
    GraphAdjacencyList& operator=(const GraphAdjacencyList&);
    GraphAdjacencyList& operator=(const GraphAdjacencyList&&);

};

template<class T>
GraphAdjacencyList<T>::GraphAdjacencyList()
{
    // Nothing
}
template<class T>
GraphAdjacencyList<T>::GraphAdjacencyList(const GraphAdjacencyList<T>& g)
{
    *this = g;
}
template<class T>
GraphAdjacencyList<T>::GraphAdjacencyList(GraphAdjacencyList&& g)
{
    *this = std::move(g);
}
template<class T>
GraphAdjacencyList<T>::GraphAdjacencyList(ListSequence<List> l)
{
    AdjacencyList = l; // Realization
}
template<class T>
GraphAdjacencyList<T>::~GraphAdjacencyList()
{
}

template<class T>
GraphAdjacencyList<T>& GraphAdjacencyList<T>::operator=(const GraphAdjacencyList<T>& g)
{
    // Realization
    this->V = g.V;

    return *this;
}
template<class T>
GraphAdjacencyList<T>& GraphAdjacencyList<T>::operator=(const GraphAdjacencyList<T>&& g)
{
    // Realization
    if (&g != this)
    {
        this->V = std::move(g.V);
    }
    return *this;
}

}