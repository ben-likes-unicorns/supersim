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
#include "traffic/distribution/DistributionTrafficPattern.h"

#include <factory/Factory.h>

#include <cassert>

DistributionTrafficPattern::DistributionTrafficPattern(
    const std::string& _name, const Component* _parent,
    u32 _numTerminals, u32 _self, Json::Value _settings)
    : Component(_name, _parent), numTerminals_(_numTerminals), self_(_self) {
  assert(numTerminals_ > 0);
  assert(self_ < numTerminals_);
}

DistributionTrafficPattern::~DistributionTrafficPattern() {}

DistributionTrafficPattern* DistributionTrafficPattern::create(
    const std::string& _name, const Component* _parent, u32 _numTerminals,
    u32 _self, Json::Value _settings) {
  // retrieve type
  const std::string& type = _settings["type"].asString();

  // try to construct a traffic pattern
  DistributionTrafficPattern* tp = factory::Factory<
    DistributionTrafficPattern, DISTRIBUTIONTRAFFICPATTERN_ARGS>
      ::create(type, _name, _parent, _numTerminals, _self, _settings);

  // check that the factory had an entry for that type
  if (tp == nullptr) {
    fprintf(stderr, "unknown distribution traffic pattern: %s\n", type.c_str());
    assert(false);
  }
  return tp;
}
