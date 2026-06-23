#pragma once

#include "gui/ui_element.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>
#include <optional>
#include <vector>

class Frame : public UIElement {
  public:
    /** Constructor for the Frame class. */
    Frame();
    virtual ~Frame() = default;

    /** Frames are not selectable.
     *
     * @return False, since frames are not selectable.
     */
    virtual bool is_selectable() const override { return false; }

    /** Check if the frame has a selected child.
     *
     * @return True if a child is selected, false otherwise.
     */
    bool has_selection() const { return m_selected_child >= 0; }
    /** Select a child UIElement within the frame by its index.
     *
     * @param index The index of the child to select.
     */
    void select(std::size_t index);
    /** Select the next child UIElement within the frame. */
    void select_next();
    /** Select the previous child UIElement within the frame. */
    void select_previous();

    /** Add a child UIElement to the Frame at a specific index.
     *
     * When the frame is rendered, it will render all of its children in the
     * order they were added. The index is optional; if not provided, the child
     * will be added to the end of the list. If the index is out of bounds, the
     * child will be added to the end of the list.
     *
     * @param component The UIElement to add.
     * @param index The index at which to insert the UIElement.
     */
    void pack(const std::shared_ptr<UIElement>& component,
        std::optional<std::size_t>              index = std::nullopt);

  private:
    /** Draw the frame to the target.
     *
     * The frame will draw all of it's children in the order they were added.
     * The frame itself does not have any visual representation, it is simply a
     * container for other UIElements.
     *
     * @param target The render target to draw to.
     * @param states The render states to use for drawing.
     */
    virtual void draw(
        sf::RenderTarget& target, sf::RenderStates states) const override;

    std::vector<std::shared_ptr<UIElement>> m_children;
    int                                     m_selected_child;
};
