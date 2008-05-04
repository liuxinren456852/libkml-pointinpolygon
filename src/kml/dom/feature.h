// Copyright 2008, Google Inc. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  3. Neither the name of Google Inc. nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
// EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// This file contains the declaration of the abstract Feature element.

#ifndef KML_DOM_FEATURE_H__
#define KML_DOM_FEATURE_H__

#include "kml/dom/abstractview.h"
#include "kml/dom/extendeddata.h"
#include "kml/dom/kml22.h"
#include "kml/dom/kml_ptr.h"
#include "kml/dom/object.h"
#include "kml/dom/region.h"
#include "kml/dom/snippet.h"
#include "kml/dom/styleselector.h"
#include "kml/dom/timeprimitive.h"
#include "kml/util/util.h"

namespace kmldom {

class Feature : public Object {
 public:
  virtual ~Feature();
  virtual KmlDomType Type() const { return Type_Feature; }
  virtual bool IsA(KmlDomType type) const {
    return type == Type_Feature || Object::IsA(type);
  }

  // <name>
  const std::string& name() const { return name_; }
  bool has_name() const { return has_name_; }
  void set_name(const std::string& value) {
    name_ = value;
    has_name_ = true;
  }
  void clear_name() {
    name_.clear();
    has_name_ = false;
  }

  // <visibility>
  bool visibility() const { return visibility_; }
  bool has_visibility() const { return has_visibility_; }
  void set_visibility(bool value) {
    visibility_ = value;
    has_visibility_ = true;
  }
  void clear_visibility() {
    visibility_ = true;  // Default <visibility> is true.
    has_visibility_ = false;
  }

  // <open>
  bool open() const { return open_; }
  bool has_open() const { return has_open_; }
  void set_open(bool value) {
    open_ = value;
    has_open_ = true;
  }
  void clear_open() {
    open_ = false;
    has_open_ = false;
  }

  // <address>
  const std::string& address() const { return address_; }
  bool has_address() const { return has_address_; }
  void set_address(const std::string& value) {
    address_ = value;
    has_address_ = true;
  }
  void clear_address() {
    address_.clear();
    has_address_ = false;
  }

  // <phoneNumber>
  const std::string& phonenumber() const { return phonenumber_; }
  bool has_phonenumber() const { return has_phonenumber_; }
  void set_phonenumber(const std::string& value) {
    phonenumber_ = value;
    has_phonenumber_ = true;
  }
  void clear_phonenumber() {
    phonenumber_.clear();
    has_phonenumber_ = false;
  }

  // <Snippet>
  const SnippetPtr snippet() const { return snippet_; }
  bool has_snippet() const { return snippet_ != NULL; }
  void set_snippet(const SnippetPtr& snippet) {
    SetComplexChild(snippet, &snippet_);
  }
  void clear_snippet() {
    set_snippet(NULL);
  }

  // <description>
  const std::string& description() const { return description_; }
  bool has_description() const { return has_description_; }
  void set_description(const std::string& value) {
    description_ = value;
    has_description_ = true;
  }
  void clear_description() {
    description_.clear();
    has_description_ = false;
  }

  // AbstractView
  const AbstractViewPtr abstractview() const { return abstractview_; }
  bool has_abstractview() const { return abstractview_ != NULL; }
  void set_abstractview(const AbstractViewPtr& abstractview) {
    SetComplexChild(abstractview, &abstractview_);
  }
  void clear_abstractview() {
    set_abstractview(NULL);
  }

  // TimePrimitive
  const TimePrimitivePtr timeprimitive() const { return timeprimitive_; }
  bool has_timeprimitive() const { return timeprimitive_ != NULL; }
  void set_timeprimitive(const TimePrimitivePtr& timeprimitive) {
    SetComplexChild(timeprimitive, &timeprimitive_);
  }
  void clear_timeprimitive() {
    set_timeprimitive(NULL);
  }

  // <styleUrl>
  const std::string& styleurl() const { return styleurl_; }
  std::string& styleurl() { return styleurl_; }
  bool has_styleurl() const { return has_styleurl_; }
  void set_styleurl(const std::string& value) {
    styleurl_ = value;
    has_styleurl_ = true;
  }
  void clear_styleurl() {
    styleurl_.clear();
    has_styleurl_ = false;
  }

  // StyleSelector
  const StyleSelectorPtr styleselector() const { return styleselector_; }
  bool has_styleselector() const { return styleselector_ != NULL; }
  void set_styleselector(const StyleSelectorPtr& styleselector) {
    SetComplexChild(styleselector, &styleselector_);
  }
  void clear_styleselector() {
    set_styleselector(NULL);
  }

  // <Region>
  const RegionPtr region() const { return region_; }
  bool has_region() const { return region_ != NULL; }
  void set_region(const RegionPtr& region) {
    SetComplexChild(region, &region_);
  }
  void clear_region() {
    set_region(NULL);
  }

  // <ExtendedData>
  const ExtendedDataPtr extendeddata() const { return extendeddata_; }
  bool has_extendeddata() const { return extendeddata_ != NULL; }
  void set_extendeddata(const ExtendedDataPtr& extendeddata) {
    SetComplexChild(extendeddata, &extendeddata_);
  }
  void clear_extendeddata() {
    set_extendeddata(NULL);
  }

 protected:
  // Feature is abstract.
  Feature();
  virtual void AddElement(const ElementPtr& element);
  virtual void Serialize(Serializer& serialize) const;

 private:
  std::string name_;
  bool has_name_;
  bool visibility_;
  bool has_visibility_;
  bool open_;
  bool has_open_;
  std::string address_;
  bool has_address_;
  std::string phonenumber_;
  bool has_phonenumber_;
  SnippetPtr snippet_;
  std::string description_;
  bool has_description_;
  AbstractViewPtr abstractview_;
  TimePrimitivePtr timeprimitive_;
  std::string styleurl_;
  bool has_styleurl_;
  StyleSelectorPtr styleselector_;
  RegionPtr region_;
  ExtendedDataPtr extendeddata_;
  DISALLOW_EVIL_CONSTRUCTORS(Feature);
};

}  // namespace kmldom

#endif  // KML_DOM_FEATURE_H__
