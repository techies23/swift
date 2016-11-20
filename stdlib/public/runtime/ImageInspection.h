//===--- ImageInspection.h - Image inspection routines ----------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// This file includes routines that extract metadata from executable and
// dynamic library image files generated by the Swift compiler. The
// concrete implementations vary greatly by platform.
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_RUNTIME_IMAGE_INSPECTION_H
#define SWIFT_RUNTIME_IMAGE_INSPECTION_H

#include <cstdint>

namespace swift {

/// Load the metadata from the image necessary to find a type's
/// protocol conformance.
void initializeProtocolConformanceLookup();

/// Load the metadata from the image necessary to find a type by name.
void initializeTypeMetadataRecordLookup();

// Callbacks to register metadata from an image to the runtime.

void addImageProtocolConformanceBlockCallback(const void *start,
                                              uintptr_t size);
void addImageTypeMetadataRecordBlockCallback(const void *start,
                                             uintptr_t size);

} // end namespace swift

#endif // SWIFT_RUNTIME_IMAGE_INSPECTION_H