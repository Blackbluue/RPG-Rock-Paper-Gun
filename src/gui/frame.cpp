#include "gui/frame.hpp"

Frame::Frame() : m_children(), m_selected_child(-1) {}

void Frame::select(std::size_t index) {
    if (index > m_children.size()) {
        m_selected_child = -1;
    } else {
        m_selected_child = static_cast<int>(index);
    }
}

void Frame::select_next() {
    if (m_children.empty()) {
        m_selected_child = -1;
    } else if (m_selected_child == -1) {
        m_selected_child = 0;
    } else if (m_selected_child >= m_children.size() - 1) {
        m_selected_child = static_cast<int>(m_children.size()) - 1;
    } else {
        m_selected_child += 1;
    }
}

void Frame::select_previous() {
    if (m_children.empty()) {
        m_selected_child = -1;
    } else if (m_selected_child == -1) {
        m_selected_child = static_cast<int>(m_children.size()) - 1;
    } else {
        m_selected_child -= 1;
    }
}

void Frame::pack(const std::shared_ptr<UIElement>& component,
    std::optional<std::size_t>                     index) {
    auto offset = index.value_or(m_children.size());
    m_children.insert(m_children.begin() + offset, component);
}

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    for (const auto& child : m_children) {
        target.draw(*child, states);
    }
}
