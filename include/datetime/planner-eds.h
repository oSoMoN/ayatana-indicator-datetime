/*
 * Copyright 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *   Charles Kerr <charles.kerr@canonical.com>
 */

#ifndef INDICATOR_DATETIME_PLANNER_EDS_H
#define INDICATOR_DATETIME_PLANNER_EDS_H

#include <datetime/planner-range.h>

#include <datetime/engine-eds.h>
#include <datetime/timezone.h>

#include <memory> // shared_ptr, unique_ptr

namespace unity {
namespace indicator {
namespace datetime {

/**
 * \brief An EDS-based #RangePlanner
 */
class EdsPlanner: public RangePlanner
{
public:
    EdsPlanner(const std::shared_ptr<EdsEngine>& eds_engine,
               const std::shared_ptr<Timezone>& timezone);
    virtual ~EdsPlanner();

    core::Property<std::vector<Appointment>>& appointments();

protected:
    void rebuild_now();

private:
    std::shared_ptr<EdsEngine> m_engine;
    std::shared_ptr<Timezone> m_timezone;
    core::Property<std::vector<Appointment>> m_appointments;
};

} // namespace datetime
} // namespace indicator
} // namespace unity

#endif // INDICATOR_DATETIME_PLANNER_EDS_H
