// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/*! 
 * @file LaserScan.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */
#ifndef _SENSOR_MSGS_LASER_SCAN_HPP_
#define _SENSOR_MSGS_LASER_SCAN_HPP_


#include "../topic.hpp"

#include "../std_msgs/Header.hpp"

namespace sensor_msgs {


class LaserScan : public ros2::Topic<LaserScan>
{
public: 
    std_msgs::Header header;
    float angle_min;
    float angle_max;
    float angle_increment;
    float time_increment;
    float scan_time;
    float range_min;
    float range_max;
    float* ranges;
    uint32_t ranges_size;
    float* intensities;
    uint32_t intensities_size;

  LaserScan():
    Topic("sensor_msgs::msg::dds_::LaserScan_", "LaserScan", SENSOR_MSGS_LASER_SCAN_ID),
    header(),
    angle_min(0), angle_max(0), angle_increment(0), time_increment(0),
    scan_time(0), range_min(0), range_max(0),
    ranges(NULL), ranges_size(0),
    intensities(NULL), intensities_size(0)
  { 
  }

  bool serialize(void* msg_buf, const LaserScan* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) header.serialize(writer, &topic->header);
    (void) ucdr_serialize_float(writer, topic->angle_min);
    (void) ucdr_serialize_float(writer, topic->angle_max);
    (void) ucdr_serialize_float(writer, topic->angle_increment);
    (void) ucdr_serialize_float(writer, topic->time_increment);
    (void) ucdr_serialize_float(writer, topic->scan_time);
    (void) ucdr_serialize_float(writer, topic->range_min);
    (void) ucdr_serialize_float(writer, topic->range_max);
    (void) ucdr_serialize_sequence_float(writer, topic->ranges, topic->ranges_size);
    (void) ucdr_serialize_sequence_float(writer, topic->intensities, topic->intensities_size);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, LaserScan* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    (void) header.deserialize(reader, &topic->header);
    (void) ucdr_deserialize_float(reader, &topic->angle_min);
    (void) ucdr_deserialize_float(reader, &topic->angle_max);
    (void) ucdr_deserialize_float(reader, &topic->angle_increment);
    (void) ucdr_deserialize_float(reader, &topic->time_increment);
    (void) ucdr_deserialize_float(reader, &topic->scan_time);
    (void) ucdr_deserialize_float(reader, &topic->range_min);
    (void) ucdr_deserialize_float(reader, &topic->range_max);
    (void) ucdr_deserialize_sequence_float(reader, topic->ranges, sizeof(topic->ranges)/sizeof(float), &topic->ranges_size);
    (void) ucdr_deserialize_sequence_float(reader, topic->intensities, sizeof(topic->intensities)/sizeof(float), &topic->intensities_size);

    return !reader->error;
  }

  uint32_t size_of_topic(const LaserScan* topic, uint32_t size)
  {
    uint32_t previousSize = size;
    size += header.size_of_topic(&topic->header, size);
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + (topic->ranges_size * 4);
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + (topic->intensities_size * 4);

    return size - previousSize;
  }

};

} // namespace sensor_msgs


#endif // _SENSOR_MSGS_LASER_SCAN_HPP_
