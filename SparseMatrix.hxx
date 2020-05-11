#ifndef __PUJ__SparseMatrix__hxx__
#define __PUJ__SparseMatrix__hxx__

// --------------------------------------------------------------------
template< class _TValue >
PUJ::SparseMatrix< _TValue >::
SparseMatrix( )
  : TMatrix( )
{
}

// --------------------------------------------------------------------
template< class _TValue >
PUJ::SparseMatrix< _TValue >::
~SparseMatrix( )
{
}

// --------------------------------------------------------------------
template< class _TValue >
unsigned long PUJ::SparseMatrix< _TValue >::
GetSize( ) const
{
  return 0;//hay que arreglar
}

// --------------------------------------------------------------------
template< class _TValue >
bool PUJ::SparseMatrix< _TValue >::
HasIndex( const long& a, const long& b ) const
{
  typename TMatrix::const_iterator r = this->find( a );
  if( r != this->end( ) )
    return( r->second.find( b ) != r->second.end( ) );
  else
    return( false );
}

#endif // __PUJ__SparseMatrix__hxx__

// eof

