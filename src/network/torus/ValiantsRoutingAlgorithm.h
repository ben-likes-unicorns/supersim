/*
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef NETWORK_TORUS_VALIANTSROUTINGALGORITHM_H_
#define NETWORK_TORUS_VALIANTSROUTINGALGORITHM_H_

#include <prim/prim.h>

#include <string>
#include <vector>

#include "event/Component.h"
#include "network/torus/RoutingAlgorithm.h"
#include "router/Router.h"

namespace Torus {

class ValiantsRoutingAlgorithm : public RoutingAlgorithm {
 public:
  ValiantsRoutingAlgorithm(
      const std::string& _name, const Component* _parent, Router* _router,
      u32 _baseVc, u32 _numVcs, u32 _inputPort, u32 _inputVc,
      const std::vector<u32>& _dimensionWidths, u32 _concentration,
      Json::Value _settings);
  ~ValiantsRoutingAlgorithm();

 protected:
  void processRequest(
      Flit* _flit, RoutingAlgorithm::Response* _response) override;
};

}  // namespace Torus

#endif  // NETWORK_TORUS_VALIANTSROUTINGALGORITHM_H_
