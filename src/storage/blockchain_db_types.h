// Copyright (c) 2018-2019 VMware, Inc. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0
// This product is licensed to you under the Apache 2.0 license (the
// "License").  You may not use this product except in compliance with the
// Apache 2.0 License.
//
// This product may include a number of subcomponents with separate copyright
// notices and license terms. Your use of these subcomponents is subject to the
// terms and conditions of the subcomponent's license, as noted in the LICENSE
// file.

#ifndef CONCORD_STORAGE_BLOCKCHAIN_DB_TYPES_H_
#define CONCORD_STORAGE_BLOCKCHAIN_DB_TYPES_H_

#include <cstdint>
#include <unordered_map>
#include <vector>
#include "SimpleBCStateTransfer.hpp"
#include "consensus/sliver.hpp"

namespace concord {
namespace storage {

struct BlockHeader {
  uint32_t numberOfElements;
  uint32_t parentDigestLength;
  int8_t
      parentDigest[bftEngine::SimpleBlockchainStateTransfer::BLOCK_DIGEST_SIZE];
};

// BlockEntry structures are coming immediately after the header.
struct BlockEntry {
  uint32_t keyOffset;
  uint32_t keySize;
  uint32_t valOffset;
  uint32_t valSize;
};

enum class EDBKeyType : std::uint8_t {
  E_DB_KEY_TYPE_FIRST = 1,
  E_DB_KEY_TYPE_BLOCK = E_DB_KEY_TYPE_FIRST,
  E_DB_KEY_TYPE_KEY,
  E_DB_KEY_TYPE_BFT_METADATA_KEY,
  E_DB_KEY_TYPE_LAST
};

typedef uint64_t BlockId;
typedef uint32_t ObjectId;
typedef concord::consensus::Sliver Key;
typedef concord::consensus::Sliver Value;
typedef std::pair<Key, Value> KeyValuePair;
typedef std::unordered_map<Key, Value> SetOfKeyValuePairs;
typedef std::vector<Key> KeysVector;
typedef KeysVector ValuesVector;

}  // namespace storage
}  // namespace concord

#endif  // CONCORD_STORAGE_BLOCKCHAIN_DB_TYPES_H_
