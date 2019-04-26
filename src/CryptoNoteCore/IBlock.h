// Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Niobio Cash.
//
// Niobio Cash is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Niobio Cash is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Niobio Cash.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "CryptoNote.h"

namespace CryptoNote {
class IBlock {
public:
  virtual ~IBlock();

  virtual const Block& getBlock() const = 0;
  virtual size_t getTransactionCount() const = 0;
  virtual const Transaction& getTransaction(size_t index) const = 0;
};
}
