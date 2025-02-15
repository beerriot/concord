// Copyright (c) 2018-2019 VMware, Inc. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#ifndef CONCORD_BFT_TEST_PARAMETERS_HPP
#define CONCORD_BFT_TEST_PARAMETERS_HPP

struct ClientParams {
  uint32_t numOfOperations = 2800;
  uint16_t clientId = 4;
  uint16_t numOfReplicas = 4;
  uint16_t numOfClients = 1;
  uint16_t numOfFaulty = 1;
  uint16_t numOfSlow = 0;
  std::string configFileName;

  uint16_t get_numOfReplicas() {
    return (uint16_t)(3 * numOfFaulty + 2 * numOfSlow + 1);
  }
};

struct ReplicaParams {
  uint16_t replicaId;
  uint16_t numOfReplicas = 4;
  uint16_t numOfClients = 1;
  bool debug = false;
  bool viewChangeEnabled = false;
  uint32_t viewChangeTimeout = 60000;  // ms
  std::string configFileName;
  std::string keysFilePrefix;
};

#endif  // CONCORD_BFT_TEST_PARAMETERS_HPP
