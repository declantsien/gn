// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TOOLS_GN_NINJA_RUST_BINARY_TARGET_WRITER_H_
#define TOOLS_GN_NINJA_RUST_BINARY_TARGET_WRITER_H_

#include "gn/ninja_binary_target_writer.h"
#include "gn/output_file.h"
#include "gn/rust_tool.h"
#include "gn/target.h"

// Writes a .ninja file for a binary target type (an executable, a shared
// library, or a static library).
class NinjaRustBinaryTargetWriter : public NinjaBinaryTargetWriter {
 public:
  NinjaRustBinaryTargetWriter(const Target* target, std::ostream& out);
  ~NinjaRustBinaryTargetWriter() override;

  void Run() override;

 private:
  void WriteCompilerVars();
  void WriteSources(const OutputFile& input_dep,
                    const std::vector<OutputFile>& order_only_deps);
  // Unlike C/C++, Rust compiles all sources of a crate in one command.
  // Write a ninja variable `sources` that contains all sources and input files.
  void WriteSourcesAndInputs();
  void WriteEdition();

  const RustTool* tool_;

  NinjaRustBinaryTargetWriter(const NinjaRustBinaryTargetWriter&) = delete;
  NinjaRustBinaryTargetWriter& operator=(const NinjaRustBinaryTargetWriter&) =
      delete;
};

#endif  // TOOLS_GN_NINJA_RUST_BINARY_TARGET_WRITER_H_
