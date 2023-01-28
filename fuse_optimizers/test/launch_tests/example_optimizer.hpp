/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2020, Clearpath Robotics
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FUSE_OPTIMIZERS__TEST_EXAMPLE_OPTIMIZER_HPP_
#define FUSE_OPTIMIZERS__TEST_EXAMPLE_OPTIMIZER_HPP_

#include <fuse_optimizers/optimizer.hpp>

#include <string>
#include <utility>


/**
 * @brief Example optimizer that exposes the motion and sensor models, and the publishers, so we can check the expected
 * ones are loaded.
 */
class ExampleOptimizer : public fuse_optimizers::Optimizer
{
public:
  FUSE_SMART_PTR_DEFINITIONS(ExampleOptimizer)

  ExampleOptimizer(
    fuse_core::node_interfaces::NodeInterfaces<ALL_FUSE_CORE_NODE_INTERFACES> interfaces,
    fuse_core::Graph::UniquePtr graph = nullptr
  ) : fuse_optimizers::Optimizer(interfaces, std::move(graph))
  {
  }

  const MotionModels& getMotionModels() const
  {
    return motion_models_;
  }

  const SensorModels& getSensorModels() const
  {
    return sensor_models_;
  }

  const Publishers& getPublishers() const
  {
    return publishers_;
  }

  void transactionCallback(
      const std::string& sensor_name,
      fuse_core::Transaction::SharedPtr transaction) override
  {
    (void)sensor_name;
    (void)transaction;
  }
};

#endif  // FUSE_OPTIMIZERS__TEST_EXAMPLE_OPTIMIZER_HPP_
