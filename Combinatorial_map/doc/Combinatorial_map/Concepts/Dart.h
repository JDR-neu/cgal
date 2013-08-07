
/*!
\ingroup PkgCombinatorialMapsConcepts
\cgalConcept

The concept `Dart` defines a <I>d</I>-dimensional dart. A dart mainly
stores handles to the darts linked with itself by \f$ \beta_i\f$, \f$ \forall\f$<I>i</I>,
0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>d</I>. Moreover, it stores also handles to each
non void attribute associated with itself.

\cgalHeading{Creation}

A dart `d0` is never constructed directly, but always created
within a combinatorial map `cm` by using the method
\ref CombinatorialMap::create_dart "cm.create_dart()". A new dart is initialized to be <I>i</I>-free,
\f$ \forall\f$<I>i</I>: 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>, and having all
its attribute handles initialized to `NULL`, for each non `void` attribute.

\cgalHasModel \ref CGAL::Dart "CGAL::Dart<d,CMap>"

*/

class Dart {
public:

/// \name Constants
/// @{

/*!
The dimension of the dart.
*/
static unsigned int dimension;

/// @}

/// \name Types
/// @{

/*!
%Dart handle type.
*/
typedef unspecified_type Dart_handle;

/*!
%Dart const handle type.
*/
typedef unspecified_type Dart_const_handle;

/*!
`Attribute_handle<i>::%type` is a handle to `i`-attributes, with 0 \f$ \leq \f$ `i` \f$ \leq \f$ `dimension`.
\note It can be implemented using a nested template class.
*/
template <unsigned int i>
using Attribute_handle = unspecified_type;

/*!
`Attribute_const_handle<i>::%type` is a const handle to `i`-attributes, with 0 \f$ \leq \f$ `i` \f$ \leq \f$ `dimension`.
\note It can be implemented using a nested template class.
*/
template <unsigned int i>
using Attribute_const_handle = unspecified_type;

/// @}

/// \name Access Member Functions
/// @{

/*!
Returns \f$ \beta_i\f$(`*this`).
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>.
*/
Dart_handle beta(unsigned int i);

/*!
Returns \f$ \beta_i\f$(`*this`) when the dart is const.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>.
*/
Dart_const_handle beta(unsigned int i) const;

/*!
Returns \f$ \beta_i^{-1}\f$(`*this`).
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>.
*/
Dart_handle beta_inv(unsigned int i);

/*!
Returns \f$ \beta_i^{-1}\f$(`*this`) when the dart is const.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>.
*/
Dart_const_handle beta_inv(unsigned int i) const;

/*!
Returns true iff the dart is <I>i</I>-free.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>.
*/
bool is_free(unsigned int i) const;

/*!
Returns the highest dimension <I>i</I> such that the dart is not <I>i</I>-free.
-1 if `d0` is free for any dimension.
*/
int highest_nonfree_dimension() const;

/*!
Returns a handle to a dart belonging to the same edge
than this dart, and not to the same vertex.
`NULL` if such a dart does not exist.
*/
Dart_handle opposite();

/*!
Returns a const handle to a dart belonging to the same edge
than this dart, and not to the same vertex, when the dart is const.
`NULL` if such a dart does not exist.
*/
Dart_const_handle opposite() const;

/*!
Returns a handle to a dart belonging to the other vertex of
the edge containing this dart (but contrary to `opposite()` not
necessarily to the same edge). `NULL` if such a dart does not exist.
*/
Dart_handle other_extremity();

/*!
Returns a const handle to a dart belonging to the other vertex of
the edge containing this dart, when the dart is const (but contrary to
`opposite()` not necessarily to the same edge).
`NULL` if such a dart does not exist.
*/
Dart_const_handle other_extremity() const;

/*!
Returns a handle to the <I>i</I>-attribute associated to the dart.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>, and <I>i</I>-attributes are non `void`.
*/
template <unsigned int i> Attribute_handle<i>::type attribute();

/*!
Returns a const handle to the <I>i</I>-attribute associated to the dart,
when the dart is const.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dimension</I>, and <I>i</I>-attributes are non `void`.
*/
template <unsigned int i>
Attribute_const_handle<i>::type attribute() const;

/// @}

}; /* end Dart */

