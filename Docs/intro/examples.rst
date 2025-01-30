========
Examples
========

The Unreal ML Agents Toolkit currently includes one example environment, but many more will be added soon to highlight
the various features of the toolkit. These environments can also serve as templates for new environments or as ways to
test new ML algorithms. Environments are available on FAB under the name **UnrealMLAgentsExamples** and summarized
below.

For the environments that highlight specific features of the toolkit, we provide the training configuration file that
enables you to train the scene yourself. Currently, pre-trained model files are not included. All examples serve as
starting points for researchers and developers to explore reinforcement learning within Unreal Engine.

This page provides an overview of the example environments we offer. To learn more about designing and building your
own environments, see the :doc:`Creating a New Environment </intro/create-new-environment>` page.

BalanceABall
------------

.. image:: _images/balance_a_ball.png
   :alt: Balance A Ball Example

- **Set-up**: A balance task, where the agent (a sphere) balances a smaller ball on top.
- **Goal**: The agent must balance the ball on top for as long as possible.
- **Agents**: The environment contains 8 agents of the same kind, all using the same Behavior Parameters.
- **Agent Reward Function**:
   - The reward is calculated using a quadratic function dependent on the sphere's position. The closer the sphere is
     to the center, the higher the reward it gains. The reward decreases as the sphere moves farther to the right or left.
   - Additionally, the reward depends on the position of the ball relative to the sphere. The more centered the ball is
     relative to the sphere, the higher the reward.
   - The reward is capped between -1 and 1.
- **Behavior Parameters**:
   - Vector Observation space: 6 variables corresponding to the sphere's Y position, the smaller ball's relative
     position (Y and Z), the angle between the sphere and ball, and the ball's velocity.
   - Actions: Discrete actions with a space size of 3. Actions include no movement, movement left, or movement right by
     applying force on the Y axis of the sphere.
- **Physics Properties**:
   - The sphere (agent): 0.5 kg, locked on the X axis, can only move on the Y axis. Gravity is enabled.
   - The smaller ball: 0.05 kg, locked on the X axis, can move on the Y and Z axes. Gravity is enabled.

We hope this example inspires you to create more complex and exciting reinforcement learning environments in Unreal Engine!
