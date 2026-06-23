#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>

class UIElement : public sf::Drawable, public sf::Transformable {
  public:
    /** Constructor for the UIElement class.
     *
     * Base class for all UI elements. Provides common functionality for
     * selection, activation, and disabling.
     */
    UIElement() : m_selected(false), m_active(false), m_disabled(false) {}
    virtual ~UIElement() = default;

    /** Check if the UIElement is selectable.
     *
     * @return True if the UIElement is selectable, false otherwise.
     */
    virtual bool is_selectable() const { return false; }
    /** Check if the UIElement is selected.
     *
     * @return True if the UIElement is selected, false otherwise.
     */
    bool         is_selected() const { return m_selected; }
    /** Select the UIElement.
     *
     * This changes the UIElement's state to selected.
     */
    virtual void select() { m_selected = is_selectable() ? true : m_selected; }
    /** Deselect the UIElement.
     *
     * This changes the UIElement's state to normal.
     */
    virtual void deselect() { m_selected = false; };

    /** Check if the UIElement is active.
     *
     * @return True if the UIElement is active, false otherwise.
     */
    bool         is_active() const { return m_active; }
    /** Activate the UIElement.
     *
     * This changes the UIElement's state to active. Each derived class is free
     * to define what activation means for themselves, but the parent element
     * will always be notified of activation. A disabled element cannot be
     * activated; attempting to activate it will have no effect.
     */
    virtual void activate() { m_active = !m_disabled ? true : m_active; }
    /** Deactivate the UIElement.
     *
     * This changes the UIElement's state to normal. Generally the parent of
     * an element will notice it's child is activated, perform some task based
     * on that activation, then deactivate the child.
     */
    virtual void deactivate() { m_active = false; };

    /** Enable the UIElement.
     *
     * This allows the UIElement to be activated.
     */
    virtual void enable() { m_disabled = false; }
    /** Disable the UIElement.
     *
     * This prevents the UIElement from being activated.
     */
    virtual void disable() { m_disabled = true; }
    /** Check if the UIElement is disabled.
     *
     * @return True if the UIElement is disabled, false otherwise.
     */
    bool         is_disabled() const { return m_disabled; }

  protected:
    virtual void draw(
        sf::RenderTarget& target, sf::RenderStates states) const = 0;

  private:
    /** Whether the UIElement is currently selected. */
    bool m_selected;
    /** Whether the UIElement is currently active. */
    bool m_active;
    /** Whether the UIElement is disabled. */
    bool m_disabled;
};
