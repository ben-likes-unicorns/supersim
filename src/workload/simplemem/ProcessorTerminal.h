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
#ifndef WORKLOAD_SIMPLEMEM_PROCESSORTERMINAL_H_
#define WORKLOAD_SIMPLEMEM_PROCESSORTERMINAL_H_

#include <json/json.h>
#include <prim/prim.h>

#include <string>
#include <vector>

#include "event/Component.h"
#include "workload/Terminal.h"

class Application;

namespace SimpleMem {

class ProcessorTerminal : public Terminal {
 public:
  ProcessorTerminal(const std::string& _name, const Component* _parent,
                    u32 _id, const std::vector<u32>& _address,
                    ::Application* _app, Json::Value _settings);
  ~ProcessorTerminal();
  void processEvent(void* _event, s32 _type) override;
  f64 percentComplete() const;
  void start();
  void stop();

 protected:
  void handleDeliveredMessage(Message* _message) override;
  void handleReceivedMessage(Message* _message) override;

 private:
  enum class eState {kProcessing, kWaitingForReadResp, kWaitingForWriteResp,
      kDone};

  void continueProcessing();
  void startNextMemoryAccess();

  u32 trafficClass_;

  u32 totalMemory_;
  u32 memorySlice_;
  u32 blockSize_;

  u32 latency_;
  u32 numMemoryAccesses_;
  u32 remainingAccesses_;

  eState fsm_;
};

}  // namespace SimpleMem

#endif  // WORKLOAD_SIMPLEMEM_PROCESSORTERMINAL_H_
