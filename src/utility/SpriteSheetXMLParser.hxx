// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef SPRITE_SHEET_XMLPARSER_HXX
#define SPRITE_SHEET_XMLPARSER_HXX

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/types.hxx>

#include <xsd/cxx/xml/error-handler.hxx>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

#include <xsd/cxx/tree/parsing.hxx>
#include <xsd/cxx/tree/parsing/byte.hxx>
#include <xsd/cxx/tree/parsing/unsigned-byte.hxx>
#include <xsd/cxx/tree/parsing/short.hxx>
#include <xsd/cxx/tree/parsing/unsigned-short.hxx>
#include <xsd/cxx/tree/parsing/int.hxx>
#include <xsd/cxx/tree/parsing/unsigned-int.hxx>
#include <xsd/cxx/tree/parsing/long.hxx>
#include <xsd/cxx/tree/parsing/unsigned-long.hxx>
#include <xsd/cxx/tree/parsing/boolean.hxx>
#include <xsd/cxx/tree/parsing/float.hxx>
#include <xsd/cxx/tree/parsing/double.hxx>
#include <xsd/cxx/tree/parsing/decimal.hxx>

namespace xml_schema
{
  // anyType and anySimpleType.
  //
  typedef ::xsd::cxx::tree::type type;
  typedef ::xsd::cxx::tree::simple_type< char, type > simple_type;
  typedef ::xsd::cxx::tree::type container;

  // 8-bit
  //
  typedef signed char byte;
  typedef unsigned char unsigned_byte;

  // 16-bit
  //
  typedef short short_;
  typedef unsigned short unsigned_short;

  // 32-bit
  //
  typedef int int_;
  typedef unsigned int unsigned_int;

  // 64-bit
  //
  typedef long long long_;
  typedef unsigned long long unsigned_long;

  // Supposed to be arbitrary-length integral types.
  //
  typedef long long integer;
  typedef long long non_positive_integer;
  typedef unsigned long long non_negative_integer;
  typedef unsigned long long positive_integer;
  typedef long long negative_integer;

  // Boolean.
  //
  typedef bool boolean;

  // Floating-point types.
  //
  typedef float float_;
  typedef double double_;
  typedef double decimal;

  // String types.
  //
  typedef ::xsd::cxx::tree::string< char, simple_type > string;
  typedef ::xsd::cxx::tree::normalized_string< char, string > normalized_string;
  typedef ::xsd::cxx::tree::token< char, normalized_string > token;
  typedef ::xsd::cxx::tree::name< char, token > name;
  typedef ::xsd::cxx::tree::nmtoken< char, token > nmtoken;
  typedef ::xsd::cxx::tree::nmtokens< char, simple_type, nmtoken > nmtokens;
  typedef ::xsd::cxx::tree::ncname< char, name > ncname;
  typedef ::xsd::cxx::tree::language< char, token > language;

  // ID/IDREF.
  //
  typedef ::xsd::cxx::tree::id< char, ncname > id;
  typedef ::xsd::cxx::tree::idref< char, ncname, type > idref;
  typedef ::xsd::cxx::tree::idrefs< char, simple_type, idref > idrefs;

  // URI.
  //
  typedef ::xsd::cxx::tree::uri< char, simple_type > uri;

  // Qualified name.
  //
  typedef ::xsd::cxx::tree::qname< char, simple_type, uri, ncname > qname;

  // Binary.
  //
  typedef ::xsd::cxx::tree::buffer< char > buffer;
  typedef ::xsd::cxx::tree::base64_binary< char, simple_type > base64_binary;
  typedef ::xsd::cxx::tree::hex_binary< char, simple_type > hex_binary;

  // Date/time.
  //
  typedef ::xsd::cxx::tree::time_zone time_zone;
  typedef ::xsd::cxx::tree::date< char, simple_type > date;
  typedef ::xsd::cxx::tree::date_time< char, simple_type > date_time;
  typedef ::xsd::cxx::tree::duration< char, simple_type > duration;
  typedef ::xsd::cxx::tree::gday< char, simple_type > gday;
  typedef ::xsd::cxx::tree::gmonth< char, simple_type > gmonth;
  typedef ::xsd::cxx::tree::gmonth_day< char, simple_type > gmonth_day;
  typedef ::xsd::cxx::tree::gyear< char, simple_type > gyear;
  typedef ::xsd::cxx::tree::gyear_month< char, simple_type > gyear_month;
  typedef ::xsd::cxx::tree::time< char, simple_type > time;

  // Entity.
  //
  typedef ::xsd::cxx::tree::entity< char, ncname > entity;
  typedef ::xsd::cxx::tree::entities< char, simple_type, entity > entities;

  typedef ::xsd::cxx::tree::content_order content_order;
  // Flags and properties.
  //
  typedef ::xsd::cxx::tree::flags flags;
  typedef ::xsd::cxx::tree::properties< char > properties;

  // Parsing/serialization diagnostics.
  //
  typedef ::xsd::cxx::tree::severity severity;
  typedef ::xsd::cxx::tree::error< char > error;
  typedef ::xsd::cxx::tree::diagnostics< char > diagnostics;

  // Exceptions.
  //
  typedef ::xsd::cxx::tree::exception< char > exception;
  typedef ::xsd::cxx::tree::bounds< char > bounds;
  typedef ::xsd::cxx::tree::duplicate_id< char > duplicate_id;
  typedef ::xsd::cxx::tree::parsing< char > parsing;
  typedef ::xsd::cxx::tree::expected_element< char > expected_element;
  typedef ::xsd::cxx::tree::unexpected_element< char > unexpected_element;
  typedef ::xsd::cxx::tree::expected_attribute< char > expected_attribute;
  typedef ::xsd::cxx::tree::unexpected_enumerator< char > unexpected_enumerator;
  typedef ::xsd::cxx::tree::expected_text_content< char > expected_text_content;
  typedef ::xsd::cxx::tree::no_prefix_mapping< char > no_prefix_mapping;

  // Error handler callback interface.
  //
  typedef ::xsd::cxx::xml::error_handler< char > error_handler;

  // DOM interaction.
  //
  namespace dom
  {
    // Automatic pointer for DOMDocument.
    //
    using ::xsd::cxx::xml::dom::auto_ptr;

#ifndef XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
#define XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
    // DOM user data key for back pointers to tree nodes.
    //
    const XMLCh* const tree_node_key = ::xsd::cxx::tree::user_data_keys::node;
#endif
  }
}

// Forward declarations.
//
class TextureAtlas;
class sprite;

#include <memory>    // ::std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

class TextureAtlas: public ::xml_schema::type
{
  public:
  // sprite
  //
  typedef ::sprite sprite_type;
  typedef ::xsd::cxx::tree::sequence< sprite_type > sprite_sequence;
  typedef sprite_sequence::iterator sprite_iterator;
  typedef sprite_sequence::const_iterator sprite_const_iterator;
  typedef ::xsd::cxx::tree::traits< sprite_type, char > sprite_traits;

  const sprite_sequence&
  sprite () const;

  sprite_sequence&
  sprite ();

  void
  sprite (const sprite_sequence& s);

  // height
  //
  typedef ::xml_schema::integer height_type;
  typedef ::xsd::cxx::tree::traits< height_type, char > height_traits;

  const height_type&
  height () const;

  height_type&
  height ();

  void
  height (const height_type& x);

  // imagePath
  //
  typedef ::xml_schema::ncname imagePath_type;
  typedef ::xsd::cxx::tree::traits< imagePath_type, char > imagePath_traits;

  const imagePath_type&
  imagePath () const;

  imagePath_type&
  imagePath ();

  void
  imagePath (const imagePath_type& x);

  void
  imagePath (::std::auto_ptr< imagePath_type > p);

  // width
  //
  typedef ::xml_schema::integer width_type;
  typedef ::xsd::cxx::tree::traits< width_type, char > width_traits;

  const width_type&
  width () const;

  width_type&
  width ();

  void
  width (const width_type& x);

  // Constructors.
  //
  TextureAtlas (const height_type&,
                const imagePath_type&,
                const width_type&);

  TextureAtlas (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

  TextureAtlas (const TextureAtlas& x,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

  virtual TextureAtlas*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  TextureAtlas&
  operator= (const TextureAtlas& x);

  virtual 
  ~TextureAtlas ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  sprite_sequence sprite_;
  ::xsd::cxx::tree::one< height_type > height_;
  ::xsd::cxx::tree::one< imagePath_type > imagePath_;
  ::xsd::cxx::tree::one< width_type > width_;
};

class sprite: public ::xml_schema::type
{
  public:
  // h
  //
  typedef ::xml_schema::integer h_type;
  typedef ::xsd::cxx::tree::traits< h_type, char > h_traits;

  const h_type&
  h () const;

  h_type&
  h ();

  void
  h (const h_type& x);

  // n
  //
  typedef ::xml_schema::ncname n_type;
  typedef ::xsd::cxx::tree::traits< n_type, char > n_traits;

  const n_type&
  n () const;

  n_type&
  n ();

  void
  n (const n_type& x);

  void
  n (::std::auto_ptr< n_type > p);

  // oH
  //
  typedef ::xml_schema::integer oH_type;
  typedef ::xsd::cxx::tree::optional< oH_type > oH_optional;
  typedef ::xsd::cxx::tree::traits< oH_type, char > oH_traits;

  const oH_optional&
  oH () const;

  oH_optional&
  oH ();

  void
  oH (const oH_type& x);

  void
  oH (const oH_optional& x);

  // oW
  //
  typedef ::xml_schema::integer oW_type;
  typedef ::xsd::cxx::tree::optional< oW_type > oW_optional;
  typedef ::xsd::cxx::tree::traits< oW_type, char > oW_traits;

  const oW_optional&
  oW () const;

  oW_optional&
  oW ();

  void
  oW (const oW_type& x);

  void
  oW (const oW_optional& x);

  // oX
  //
  typedef ::xml_schema::integer oX_type;
  typedef ::xsd::cxx::tree::optional< oX_type > oX_optional;
  typedef ::xsd::cxx::tree::traits< oX_type, char > oX_traits;

  const oX_optional&
  oX () const;

  oX_optional&
  oX ();

  void
  oX (const oX_type& x);

  void
  oX (const oX_optional& x);

  // oY
  //
  typedef ::xml_schema::integer oY_type;
  typedef ::xsd::cxx::tree::optional< oY_type > oY_optional;
  typedef ::xsd::cxx::tree::traits< oY_type, char > oY_traits;

  const oY_optional&
  oY () const;

  oY_optional&
  oY ();

  void
  oY (const oY_type& x);

  void
  oY (const oY_optional& x);

  // pX
  //
  typedef ::xml_schema::decimal pX_type;
  typedef ::xsd::cxx::tree::traits< pX_type, char, ::xsd::cxx::tree::schema_type::decimal > pX_traits;

  const pX_type&
  pX () const;

  pX_type&
  pX ();

  void
  pX (const pX_type& x);

  // pY
  //
  typedef ::xml_schema::decimal pY_type;
  typedef ::xsd::cxx::tree::traits< pY_type, char, ::xsd::cxx::tree::schema_type::decimal > pY_traits;

  const pY_type&
  pY () const;

  pY_type&
  pY ();

  void
  pY (const pY_type& x);

  // w
  //
  typedef ::xml_schema::integer w_type;
  typedef ::xsd::cxx::tree::traits< w_type, char > w_traits;

  const w_type&
  w () const;

  w_type&
  w ();

  void
  w (const w_type& x);

  // x
  //
  typedef ::xml_schema::integer x_type;
  typedef ::xsd::cxx::tree::traits< x_type, char > x_traits;

  const x_type&
  x () const;

  x_type&
  x ();

  void
  x (const x_type& x);

  // y
  //
  typedef ::xml_schema::integer y_type;
  typedef ::xsd::cxx::tree::traits< y_type, char > y_traits;

  const y_type&
  y () const;

  y_type&
  y ();

  void
  y (const y_type& x);

  // Constructors.
  //
  sprite (const h_type&,
          const n_type&,
          const pX_type&,
          const pY_type&,
          const w_type&,
          const x_type&,
          const y_type&);

  sprite (const ::xercesc::DOMElement& e,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  sprite (const sprite& x,
          ::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0);

  virtual sprite*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  sprite&
  operator= (const sprite& x);

  virtual 
  ~sprite ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< h_type > h_;
  ::xsd::cxx::tree::one< n_type > n_;
  oH_optional oH_;
  oW_optional oW_;
  oX_optional oX_;
  oY_optional oY_;
  ::xsd::cxx::tree::one< pX_type > pX_;
  ::xsd::cxx::tree::one< pY_type > pY_;
  ::xsd::cxx::tree::one< w_type > w_;
  ::xsd::cxx::tree::one< x_type > x_;
  ::xsd::cxx::tree::one< y_type > y_;
};

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

// Parse a URI or a local file.
//

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (const ::std::string& uri,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (const ::std::string& uri,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (const ::std::string& uri,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::std::istream& is,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::std::istream& is,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::std::istream& is,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::std::istream& is,
               const ::std::string& id,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::std::istream& is,
               const ::std::string& id,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::std::istream& is,
               const ::std::string& id,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::xercesc::InputSource& is,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::xercesc::InputSource& is,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::xercesc::InputSource& is,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (const ::xercesc::DOMDocument& d,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::TextureAtlas >
TextureAtlas_ (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse a URI or a local file.
//

::std::auto_ptr< ::sprite >
sprite_ (const ::std::string& uri,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (const ::std::string& uri,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (const ::std::string& uri,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::auto_ptr< ::sprite >
sprite_ (::std::istream& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::std::istream& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::std::istream& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::std::istream& is,
         const ::std::string& id,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::std::istream& is,
         const ::std::string& id,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::auto_ptr< ::sprite >
sprite_ (::xercesc::InputSource& is,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::xercesc::InputSource& is,
         ::xml_schema::error_handler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::xercesc::InputSource& is,
         ::xercesc::DOMErrorHandler& eh,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::auto_ptr< ::sprite >
sprite_ (const ::xercesc::DOMDocument& d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::sprite >
sprite_ (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d,
         ::xml_schema::flags f = 0,
         const ::xml_schema::properties& p = ::xml_schema::properties ());

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // SPRITE_SHEET_XMLPARSER_HXX
