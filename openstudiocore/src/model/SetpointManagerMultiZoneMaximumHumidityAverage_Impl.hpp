/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef MODEL_SETPOINTMANAGERMULTIZONEMAXIMUMHUMIDITYAVERAGE_IMPL_HPP
#define MODEL_SETPOINTMANAGERMULTIZONEMAXIMUMHUMIDITYAVERAGE_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/SetpointManager_Impl.hpp>

namespace openstudio {
namespace model {

// TODO: Check the following class names against object getters and setters.
class Node;

namespace detail {

  /** SetpointManagerMultiZoneMaximumHumidityAverage_Impl is a SetpointManager_Impl that is the implementation class for SetpointManagerMultiZoneMaximumHumidityAverage.*/
  class MODEL_API SetpointManagerMultiZoneMaximumHumidityAverage_Impl : public SetpointManager_Impl {
   public:
    /** @name Constructors and Destructors */
    //@{

    SetpointManagerMultiZoneMaximumHumidityAverage_Impl(const IdfObject& idfObject,
                                                        Model_Impl* model,
                                                        bool keepHandle);

    SetpointManagerMultiZoneMaximumHumidityAverage_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                        Model_Impl* model,
                                                        bool keepHandle);

    SetpointManagerMultiZoneMaximumHumidityAverage_Impl(const SetpointManagerMultiZoneMaximumHumidityAverage_Impl& other,
                                                        Model_Impl* model,
                                                        bool keepHandle);

    virtual ~SetpointManagerMultiZoneMaximumHumidityAverage_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    std::string controlVariable() const;

    double minimumSetpointHumidityRatio() const;

    double maximumSetpointHumidityRatio() const;

    // TODO: Check return type. From object lists, some candidates are: Node.
    boost::optional<Node> setpointNodeorNodeList() const;

    //@}
    /** @name Setters */
    //@{

    bool setControlVariable(std::string controlVariable);

    bool setMinimumSetpointHumidityRatio(double minimumSetpointHumidityRatio);

    bool setMaximumSetpointHumidityRatio(double maximumSetpointHumidityRatio);

    // TODO: Check argument type. From object lists, some candidates are: Node.
    bool setSetpointNodeorNodeList(const boost::optional<Node>& node);

    void resetSetpointNodeorNodeList();

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.SetpointManagerMultiZoneMaximumHumidityAverage");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_SETPOINTMANAGERMULTIZONEMAXIMUMHUMIDITYAVERAGE_IMPL_HPP

