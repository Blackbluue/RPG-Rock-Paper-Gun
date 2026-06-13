#include "gui/ui_element.hpp"

UIElement::UIElement()
    : m_selected(false), m_active(false), m_disabled(false) {}

void UIElement::select() {
    if (is_selectable()) {
        m_selected = true;
    }
}

void UIElement::deselect() { m_selected = false; }

void UIElement::activate() {
    if (!m_disabled) {
        m_active = true;
    }
}

void UIElement::deactivate() { m_active = false; }
