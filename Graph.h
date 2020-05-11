#ifndef __PUJ__Graph__h__
#define __PUJ__Graph__h__

#include "SparseMatrix.h"
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <vector>
#include <deque>
namespace PUJ
{
  template< class _TVertex, class _TCost >
  class Graph
  {
   public:
     typedef _TVertex TVertex;
     typedef _TCost   TCost;

     typedef std::vector< TVertex >     TVertices;
     
     typedef PUJ::SparseMatrix< TCost > TMatrix;
     
     typedef std::vector < long >       TMST;

   public:
     Graph( )
     {
     }
     virtual ~Graph( )
     {
     }

     long AddVertex( const TVertex& v )
     {
       this->m_Vertices.push_back( v );
       return( this->m_Vertices.size( ) - 1 );
     }

     bool AddEdge( const long& a, const long& b, const TCost& c )
     {
       bool r = this->m_Edges.HasIndex( a, b );
       this->m_Edges[ a ][ b ] = c;
       return( r );
     }

     const TVertex& GetVertex( const long& a ) const
     {
       return( this->m_Vertices[ a ] );
     }

     const TCost& GetEdge( const long& a, const long& b ) const
     {
       return( this->m_Edges( a, b ) );
     }
     bool HasEdge( const long& a, const long& b ) const
     {
       return( this->m_Edges.HasIndex( a, b ) );
     }


     TMST Dijkstra(unsigned long seed) const
     {
       typedef std::tuple <long, long , TCost> _TNode;
       struct 
       {
         bool operator()(const _TNode& a, const _TNode& b) const
         {
           return (std::get< 2 >( b ) < std::get < 2 > ( a ) );
         }
       }comp;

       TMST mst(this->m_Vertices.size(),-1);
       std::vector< bool > marks(this->m_Vertices.size(),false);

       std::vector<_TNode> q;
       q.push_back(_TNode(seed,seed, TCost(0)));

       while (q.size()>0)
       {
         std::pop_heap(q.begin(),q.end(),comp);
         _TNode n = q.back();
         q.pop_back();
         long vertex = std::get <0>(n);
         long parent = std::get <1>(n);
         TCost cost = std::get <2>(n);
         if (!(marks[vertex]))
         {
           mst[vertex] = parent;
           marks[vertex] = true;
           
           for (long neigh  = 0; neigh < m_Vertices.size();++neigh)
           {
             if (this->HasEdge(vertex,neigh))
             {
               q.push_back(
                 _TNode(
                   neigh, vertex, cost + this->GetEdge(vertex,neigh)
                 )
               );
               std::push_heap(q.begin(),q.end(),comp);
             }             
           }           
         }     
      }  
      return (mst); 
     
     
     }


     TMST Dijkstra2(unsigned long seed) const
     {
       typedef std::tuple <long, long , TCost> _TNode;
       struct 
       {
         bool operator()(const _TNode& a, const _TNode& b) const
         {
           return (std::get< 2 >( b ) < std::get < 2 > ( a ) );
         }
       }comp;

       TMST mst(this->m_Vertices.size(),-1);
       std::vector< bool > marks(this->m_Vertices.size(),false);

       std::vector<_TNode> q;
       q.push_back(_TNode(seed,seed, TCost(0)));

       while (q.size()>0)
       {
         std::pop_heap(q.begin(),q.end(),comp);
         _TNode n = q.back();
         q.pop_back();
         long vertex = std::get <0>(n);
         long parent = std::get <1>(n);
         TCost cost = std::get <2>(n);
         if (!(marks[vertex]))
         {
           mst[vertex] = parent;
           marks[vertex] = true;
           
           for (long neigh  = 0; neigh < m_Vertices.size();++neigh)
           {
             if (this->HasEdge(vertex,neigh))
             {
               q.push_back(
                 _TNode(
                   neigh, vertex, cost + this->GetEdge(vertex,neigh)
                 )
               );
               std::push_heap(q.begin(),q.end(),comp);
             }             
           }           
         }     
      }  
      return (mst); 
     
     
     }


    




     void PrintAsPNG( const std::string& fname ) const
     {
       std::stringstream str;
       str << "echo \"digraph G{";
       unsigned long N = this->m_Vertices.size( );
       std::map< long, std::map< long, bool > > m;
       for( unsigned long i = 0; i < N; ++i )
       {
         for( unsigned long j = 0; j < N; ++j )
         {
           if( this->m_Edges.HasIndex( i, j ) )
           {
             if( !( m[ i ][ j ] ) )
             {
               str << i << "->" << j << " [label=" << this->m_Edges( i, j ) << "];";
               m[ i ][ j ] = true;
             }
           }
         } // end for
       } // end for
       str << "}\" | dot -Tpng > " << fname;
       std::system( str.str( ).c_str( ) );
     }

   protected:
     TVertices m_Vertices;
     TMatrix   m_Edges;

  };
} // end namespace


#endif // __PUJ__Graph__h__

// eof




