#ifndef __PUJ__SparseMatrix__h__
#define __PUJ__SparseMatrix__h__

#include <map>

namespace PUJ
{
  template< class _TValue >
  class SparseMatrix
    : private std::map< long, std::map< long, _TValue > >
  {
   public:
     typedef _TValue TValue;
     typedef std::map< long, TValue > TRow;
     typedef std::map< long, TRow >   TMatrix;

   public:
     SparseMatrix( );
     virtual ~SparseMatrix( );

     TRow& operator[]( const long& a )
     {
       return( this->TMatrix::operator[]( a ) );
     }

     const TValue& operator()( const long& a, const long& b ) const
     {
       typename TMatrix::const_iterator r = this->find( a );
       if( r != this->end( ) )
       {
         typename TRow::const_iterator c = r->second.find( b );
         if( c != r->second.end( ) )
           return( c->second );
         else
           throw std::runtime_error( "No sea bruto." );
       }
       else
         throw std::runtime_error( "No sea bruto." );
     }

     unsigned long GetSize( ) const;
     bool HasIndex( const long& a, const long& b ) const;

  };
} // end namespace

#include "SparseMatrix.hxx"

#endif // __PUJ__SparseMatrix__h__

// eof




