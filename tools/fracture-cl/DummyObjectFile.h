//===--- DummyObjectFile.h - [Name] ----------------------------------*- C++ -*-===//
//
//              Fracture: The Draper Decompiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// [Description]
//
// Author: rtc1032
// Date: Oct 11, 2012
//
//===----------------------------------------------------------------------===//

#ifndef DUMMYOBJECTFILE_H_
#define DUMMYOBJECTFILE_H_

#include "llvm/Object/ObjectFile.h"

namespace llvm {
namespace object {

  class DummyObjectFile : public ObjectFile {
  public:
    /* The other Object files also do not have constructor/destructors.
    DummyObjectFile();
    virtual
    ~DummyObjectFile();
    */

    DummyObjectFile(MemoryBuffer *Object, error_code &ec);

    static ObjectFile *createDummyObjectFile(MemoryBuffer *Object);

    virtual symbol_iterator begin_symbols() const;
    virtual symbol_iterator end_symbols() const;
    virtual basic_symbol_iterator symbol_begin_impl() const {
      return begin_symbols();
    }
    virtual basic_symbol_iterator symbol_end_impl() const {
      return end_symbols();
    }


    virtual symbol_iterator begin_dynamic_symbols() const;
    virtual symbol_iterator end_dynamic_symbols() const;

    virtual section_iterator begin_sections() const;
    virtual section_iterator end_sections() const;

    virtual section_iterator section_begin() const {
      return begin_sections();
    }
    virtual section_iterator section_end() const {
      return end_sections();
    }

    virtual library_iterator begin_libraries_needed() const;
    virtual library_iterator end_libraries_needed() const;
    virtual library_iterator needed_library_begin() const {
      return begin_libraries_needed();
    }
    virtual library_iterator needed_library_end() const {
      return end_libraries_needed();
    }

    /// @brief The number of bytes used to represent an address in this object
    ///        file format.
    virtual uint8_t getBytesInAddress() const;

    virtual StringRef getFileFormatName() const;
    virtual /* Triple::ArchType */ unsigned getArch() const;

    /// For shared objects, returns the name which this object should be
    /// loaded from at runtime. This corresponds to DT_SONAME on ELF and
    /// LC_ID_DYLIB (install name) on MachO.
    virtual StringRef getLoadName() const;

  protected:
    // Symbol Functions
    virtual error_code getSymbolNext(DataRefImpl Symb, SymbolRef &Res) const;
    virtual error_code getSymbolName(DataRefImpl Symb, StringRef &Res) const;
    virtual error_code getSymbolAddress(DataRefImpl Symb, uint64_t &Res) const;
    virtual error_code getSymbolFileOffset(DataRefImpl Symb,
                                           uint64_t &Res) const;
    virtual error_code getSymbolSize(DataRefImpl Symb, uint64_t &Res) const;
    virtual error_code getSymbolType(DataRefImpl Symb,
                                     SymbolRef::Type &Res) const;
    virtual error_code getSymbolNMTypeChar(DataRefImpl Symb, char &Res) const;
    virtual uint32_t getSymbolFlags(DataRefImpl Symb) const;
    virtual error_code getSymbolSection(DataRefImpl Symb,
                                        section_iterator &Res) const;
    virtual error_code getSymbolValue(DataRefImpl Symb, uint64_t &Val) const;

    // Section Functions
    virtual error_code getSectionNext(DataRefImpl Sec, SectionRef &Res) const;
    virtual error_code getSectionName(DataRefImpl Sec, StringRef &Res) const;
    virtual error_code getSectionAddress(DataRefImpl Sec, uint64_t &Res) const;
    virtual error_code getSectionSize(DataRefImpl Sec, uint64_t &Res) const;
    virtual error_code getSectionContents(DataRefImpl Sec, StringRef &Res)const;
    virtual error_code getSectionAlignment(DataRefImpl Sec, uint64_t &Res)const;
    virtual error_code isSectionText(DataRefImpl Sec, bool &Res) const;
    virtual error_code isSectionData(DataRefImpl Sec, bool &Res) const;
    virtual error_code isSectionBSS(DataRefImpl Sec, bool &Res) const;
    virtual error_code isSectionRequiredForExecution(DataRefImpl Sec,
                                                     bool &Res) const;
    // A section is 'virtual' if its contents aren't present in the object img.
    virtual error_code isSectionVirtual(DataRefImpl Sec, bool &Res) const;
    virtual error_code isSectionZeroInit(DataRefImpl Sec, bool &Res) const;
    virtual error_code isSectionReadOnlyData(DataRefImpl Sec, bool &Res) const;
    virtual error_code sectionContainsSymbol(DataRefImpl Sec, DataRefImpl Symb,
                                             bool &Result) const;
    virtual relocation_iterator getSectionRelBegin(DataRefImpl Sec) const;
    virtual relocation_iterator getSectionRelEnd(DataRefImpl Sec) const;

    // Relocations
    virtual error_code getRelocationNext(DataRefImpl Rel,
                                          RelocationRef &Res) const;
    virtual error_code getRelocationAddress(DataRefImpl Rel,
                                       uint64_t &Res) const;
    virtual error_code getRelocationOffset(DataRefImpl Rel,
                                      uint64_t &Res) const;
    virtual symbol_iterator getRelocationSymbol(DataRefImpl Rel) const;
    virtual error_code getRelocationType(DataRefImpl Rel,
                                    uint64_t &Res) const;
    virtual error_code getRelocationTypeName(DataRefImpl Rel,
                                    SmallVectorImpl<char> &Result) const;
    virtual error_code getRelocationAdditionalInfo(DataRefImpl Rel,
                                              int64_t &Res) const;
    virtual error_code getRelocationValueString(DataRefImpl Rel,
                                    SmallVectorImpl<char> &Result) const;

    //Libraries
    virtual error_code getLibraryNext(DataRefImpl Lib, LibraryRef &Res) const;
    virtual error_code getLibraryPath(DataRefImpl Lib, StringRef &Res) const;


    // Added in latest llvm-trunk update
    virtual void moveSymbolNext(DataRefImpl &Symb) const {
      return;
    }

    virtual void moveSectionNext(DataRefImpl &Sec) const {
      return;
    }

    virtual void moveRelocationNext(DataRefImpl &Rel) const {
      return;
    }

    virtual relocation_iterator section_rel_begin(DataRefImpl Sec) const {
      return getSectionRelBegin(Sec);
    }
    virtual relocation_iterator section_rel_end(DataRefImpl Sec) const {
      return getSectionRelBegin(Sec);
    }


  };

} /* namespace object */
} /* namespace llvm */
#endif /* DUMMYOBJECTFILE_H_ */
