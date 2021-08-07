#include "reward/create_component.hpp"
#include "reward/component_impl.hpp"

namespace nexuspool {
namespace reward {

Component::Uptr create_component(persistance::Shared_data_writer::Sptr shared_data_writer)
{
    return std::make_unique<Component_impl>(std::move(shared_data_writer));
}

}
}
