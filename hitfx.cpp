/* heXon
// Copyright (C) 2015 LucKey Productions (luckeyproductions.nl)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "hitfx.h"

HitFX::HitFX(Context *context, MasterControl *masterControl):
    Effect(context, masterControl)
{
    rootNode_->SetName("HitFX");
    particleEmitter_ = rootNode_->CreateComponent<ParticleEmitter>();
    greenHitFX_ = masterControl_->cache_->GetResource<ParticleEffect>("Resources/Particles/GreenHitFX.xml");
    purpleHitFX_ = masterControl_->cache_->GetResource<ParticleEffect>("Resources/Particles/PurpleHitFX.xml");

    sample_ = masterControl_->cache_->GetResource<Sound>("Resources/Samples/Hit.ogg");
    sample_->SetLooped(false);
}

void HitFX::Set(const Vector3 position, const bool sound, int playerID)
{
    particleEmitter_->SetEffect(playerID == 2 ? purpleHitFX_ : greenHitFX_);

    if (sound) PlaySample(sample_, 0.23f);
    Effect::Set(position);
}
